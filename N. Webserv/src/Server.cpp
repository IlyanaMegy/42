#include "Server.hpp"

Server::Server(int port) : _socket(port)
{
  __setOptions()
  // for later try catch ?

  if (listen(_socket, 5) == -1) {
    std::cerr << "Erreur lors du listen" << std::endl;
    close(_socket);
    exit(EXIT_FAILURE);
  }
  std::cout << "listening..." << std::endl;
}

Server::~Server(void){}

int Server::getSocket(void) const
{

}

Client &Server::getClient(int i) const
{

}

void Server::acceptClient(void)
{

}

void Server::readFrom(int i)
{
  
}

void Server::send(int fd)
{
  
}

const char *Server::SocketCreationErrException::what() const throw() {
  std::cerr << "Erreur lors de la création du socket" << std::endl;
  exit(EXIT_FAILURE);
}
