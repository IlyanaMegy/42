#include "../inc/Server.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <sys/epoll.h>
#include <vector>

#define FILE "configs/default.conf"

int main(void) {
  // std::string config;
  // if (ac <= 2)
  // {
  //     try
  //     {
  //         // Parse with default conf OR av[1]
  //         config = (ac == 1 ? FILE : av[1]);

  //         // Check and read config file
  //         // define if path is file, folder or something else
  //         // check if the file exists and accessible
  //         // read file, check if empty
  //         // remove comments and spaces
  //         // split servers ?
  //         // create server
  //         // check servers

  //         // Setup servers on ports specified in the config file

  //         // Run servers
  //         /**
  //          * Runs main loop that goes through all file descriptors from 0
  //          till the biggest fd in the set.
  //          * - check file descriptors returend from select():
  //          *      if server fd --> accept new client
  //          *      if client fd in read_set --> read message from client
  //          *      if client fd in write_set:
  //          *          1- If it's a CGI response and Body still not sent to
  //          CGI child process --> Send request body to CGI child process.
  //          *          2- If it's a CGI response and Body was sent to CGI
  //          child process --> Read outupt from CGI child process.
  //          *          3- If it's a normal response --> Send response to
  //          client.
  //          * - servers and clients sockets will be added to _recv_set_pool
  //          initially,
  //          *   after that, when a request is fully parsed, socket will be
  //          moved to _write_set_pool
  //          */
  //     }
  //     catch (const std::exception &e)
  //     {
  //         std::cerr << e.what() << '\n';
  //     }
  // }
  // else
  //     return (std::cerr << "usage: ./webserv <path to configuration file> or
  //     just ./webserv" << std::endl, 1);

  Server server;
  char buff[BUFFER_SIZE];

  // Descriptors' list to watch with poll()
  std::vector<struct pollfd> fds;

  // Add server's socket to the list
  struct pollfd server_pollfd;
  server_pollfd.fd = server._socket;
  server_pollfd.events = POLLIN;
  fds.push_back(server_pollfd);

  while (1) {
    // Call poll to watch descriptors
    int poll_count = poll(fds.data(), fds.size(), 5000); // illimited timeout
    if (poll_count == -1) {
      std::cerr << "Erreur avec poll" << std::endl;
      break;
    }

    for (size_t i = 0; i < fds.size(); i++) {
      if (fds[i].revents & POLLIN) {
        if (fds[i].fd == server._socket) {

          // New incoming connection
          int client_socket = accept(server._socket, NULL, NULL);
          if (client_socket == -1) {
            std::cerr << "Erreur lors de l'acceptation du client" << std::endl;
            continue;
          }
          std::cout << "Client accepté : " << client_socket << std::endl;

          // Add client to descriptors' list
          struct pollfd client_pollfd;
          client_pollfd.fd = client_socket;
          client_pollfd.events = POLLIN;
          fds.push_back(client_pollfd);
        } else {

          // HTTP Request of existing client
          memset(buff, 0, BUFFER_SIZE);
          ssize_t res = recv(fds[i].fd, buff, BUFFER_SIZE - 1, 0);

          if (res > 0) {

            // HTTP Response
            std::cout << "Reçu : " << buff << std::endl;
            std::string response =
                "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
            send(fds[i].fd, response.c_str(), response.length(), 0);
          } else if (res == 0) {
            // client has closed connection
            std::cout << "Client déconnecté : " << fds[i].fd << std::endl;
            close(fds[i].fd);
            fds.erase(fds.begin() + i);
            --i; // Fix index after suppression
          } else {
            std::cerr << "Erreur lors de la réception de données" << std::endl;
            close(fds[i].fd);
            fds.erase(fds.begin() + i);
            --i;
          }
        }
      }
    }
  }
  return 0;
}
