#include "../inc/Server.hpp"
#include <iostream>

Server::Server() {
  int opt = 1;

  // Creation socket
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (_socket == -1)
    SocketCreationErrException();

  _sockAddr.sin_family = AF_INET;
  _sockAddr.sin_port = htons(9001);
  _sockAddr.sin_addr.s_addr = INADDR_ANY;
  setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  if (bind(_socket, (struct sockaddr *)&_sockAddr, sizeof(_sockAddr)) == -1) {
    std::cerr << "Erreur lors du bind" << std::endl;
    close(_socket);
    exit(EXIT_FAILURE);
  }
  std::cout << "start" << std::endl;

  if (listen(_socket, 5) == -1) {
    std::cerr << "Erreur lors du listen" << std::endl;
    close(_socket);
    exit(EXIT_FAILURE);
  }
  std::cout << "listening..." << std::endl;
}

void Server::readFrom(int i)
{
  
}

Server::~Server() {close(this->_socket);}

const char *Server::SocketCreationErrException::what() const throw() {
  std::cerr << "Erreur lors de la création du socket" << std::endl;
  exit(EXIT_FAILURE);
}
