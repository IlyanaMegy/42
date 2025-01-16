#include "../inc/Epoll.hpp"
#include <cstddef>
#include <iostream>

// #include <vector>

#define PORT 8080

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
  // verifs
  Epoll epoll(server);

  while (true) {

    try {
      epoll.wait();
    } catch (std::exception &e) {
      // epoll_ctl
      std::cout << e.what() << std::endl;
    }

    // Parcourir les événements
    for (int i = 0; i < epoll.getReadyFd(); i++) {

      // CASE SERVER
      if (epoll.getFd(i) == server.getSocket()) {

        // // Nouvelle connexion
        // int client_socket = accept(server._socket, NULL, NULL);
        // if (client_socket == -1) {
        //   perror("err while trying accept()");
        //   continue;
        // }
        // std::cout << "New connection accepted." << std::endl;
        // // Mettre le socket client en mode non-bloquant
        // make_socket_non_blocking(client_socket);

        // CLIENT CLASS
        int client_socket_to_define;
        server.acceptClient();
        // in acceptClient() ==> epoll.addFD(client_socket_to_define, EPOLLIN);

      } else {
        server.readFrom(i);
        // Événement sur un socket client
        // char buffer[BUFFER_SIZE];
        // ssize_t bytes_read = recv(events[i].data.fd, buffer, BUFFER_SIZE, 0);
        // if (bytes_read <= 0) {
        //   // Connexion fermée ou erreur
        //   if (bytes_read == 0) {
        //     std::cout << "Client disconnected." << std::endl;
        //   } else {
        //     perror("recv");
        //   }
        // }
        continue;
        
        // else {

          // ---------------------------------------------------------------------------------------------
          // ---------------------------------------------------------------------------------------------
          // // HTTP Request saved in buffer var
          // // Traiter la requête et envoyer une réponse
          // buffer[bytes_read] = '\0';
          // std::cout << "Received: " << buffer << std::endl;


          // HTTP Response      
          // send(events[i].data.fd, response.c_str(), response.size(), 0);  
          // verifs  
          server.send(i);
          
        }
      }
    }
  }

  // ---------------------------------------------------------------------------------------------
  // ---------------------------------------------------------------------------------------------
  // Nettoyage
  // close(server._socket);
  // close(run.epoll_fd);

  return 0;
}
