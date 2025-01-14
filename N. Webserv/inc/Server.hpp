<<<<<<< HEAD
#include <exception>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>

=======
#include <sys/socket.h>
#include <exception>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 15

>>>>>>> 710d51a41acd40ceee584b37f7d964b5dda871f2
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
