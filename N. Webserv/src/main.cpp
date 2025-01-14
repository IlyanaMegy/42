#include "../inc/Server.hpp"
#include <cstddef>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <sys/epoll.h>
// #include <vector>

#define PORT 8080
#define BUFFER_SIZE 42
#define MAX_EVENTS 10
#define FILE "configs/default.conf"

// Fonction pour mettre un socket en mode non-bloquant
int make_socket_non_blocking(int socket_fd) {
  int flags = fcntl(socket_fd, F_GETFL, 0);
  if (flags == -1) {
    perror("fcntl(F_GETFL)");
    return -1;
  }

  flags |= O_NONBLOCK;
  if (fcntl(socket_fd, F_SETFL, flags) == -1) {
    perror("fcntl(F_SETFL)");
    return -1;
  }

  return 0;
}

int main(void) {
  Server server;
  int epoll_fd;
  struct epoll_event event;
  struct epoll_event events[MAX_EVENTS];

  // Créer un epoll instance
  epoll_fd = epoll_create1(0);
  if (epoll_fd == -1) {
    perror("epoll_create1");
    close(server._socket);
    return 1;
  }

  // Ajouter le socket serveur à epoll
  event.events = EPOLLIN;
  event.data.fd = server._socket;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server._socket, &event) == -1) {
    perror("epoll_ctl");
    close(server._socket);
    close(epoll_fd);
    return 1;
  }

  while (true) {

    // Attendre des événements
    int num_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    if (num_fds == -1) {
      perror("epoll_wait");
      break;
    }

    // Parcourir les événements
    for (int i = 0; i < num_fds; ++i) {
      if (events[i].data.fd == server._socket) {
        // Nouvelle connexion
        int client_socket = accept(server._socket, NULL, NULL);
        if (client_socket == -1) {
          perror("accept");
          continue;
        }

        std::cout << "New connection accepted." << std::endl;

        // Mettre le socket client en mode non-bloquant
        make_socket_non_blocking(client_socket);

        // Ajouter le socket client à epoll
        event.events = EPOLLIN | EPOLLET; // Edge-triggered mode
        event.data.fd = client_socket;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &event) == -1) {
          perror("epoll_ctl");
          close(client_socket);
        }
      } else {

        // Événement sur un socket client
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = recv(events[i].data.fd, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {

          // Connexion fermée ou erreur
          if (bytes_read == 0) {
            std::cout << "Client disconnected." << std::endl;
          } else {
            perror("recv");
          }
          close(events[i].data.fd);
        } else {

          // Traiter la requête et envoyer une réponse
          buffer[bytes_read] = '\0';
          std::cout << "Received: " << buffer << std::endl;

          std::string response =
              "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
          send(events[i].data.fd, response.c_str(), response.size(), 0);
        }
      }
    }
  }

  // Nettoyage
  close(server._socket);
  close(epoll_fd);

  return 0;
}
