#include <exception>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>

class Server {
private:
  int _port;
  struct sockaddr_in _sockAddr;
  // int _socket;
public:
  Server();
  ~Server();
  int _socket;
  class SocketCreationErrException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};
