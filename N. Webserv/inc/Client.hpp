#include "Epoll.hpp"
#define BUFFER_SIZE 42

class Client {

private:
  char buffer[BUFFER_SIZE];
  // HTTPReq request;
  // HTTPRep reponse;
  struct sockaddr_in _sockAddr;
  int _socket;

public:
  Client();
  ~Client();
  int getSocket() const;
  void read();

};