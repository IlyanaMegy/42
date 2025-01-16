#include <exception>
#include <netinet/in.h>
#include <poll.h>
#include <iostream>
#include"Client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <map>

class Server {
private:
  std::map<int, Client> _clients;
  // std::vector<int> port
  int _port;
  struct sockaddr_in _sockAddr;
  int _socket;

public:
  Server();
  // Server(std::string conf_file);
  ~Server();
  int getSocket() const;
  void acceptClient();
  void readFrom(int i);
  Client  &getClient(int i);
  void send(int fd);
  class SocketCreationErrException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};
