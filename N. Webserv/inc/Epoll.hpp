#include "../inc/Server.hpp"
#include <cstring>
#include <fcntl.h>
#include <sys/epoll.h>

class Server;
#define MAX_EVENTS 10
class Epoll {
private:
  int _epollFd;
  int _readyFd;
  struct epoll_event _events[MAX_EVENTS];

public:
  Epoll(Server const &server);
  ~Epoll(void);
  int getEvents(int i) const;
  int getEpollFd() const;
  int getFd(int i) const;
  int getReadyFd() const;

  void  addFD(int fd, int flags);
  void wait();
};