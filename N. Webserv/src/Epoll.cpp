#include "../inc/Epoll.hpp"


Epoll::~Epoll(void)
{
  close(_epollFd);
}

Epoll::Epoll(const Server &server) 
{
  // Créer un epoll instance
  _epollFd = epoll_create(1);
  if (_epollFd == -1)
    throw std::exception();

  // Ajouter le socket serveur à epoll
  try {
    addFd(server.getSocket(), EPOLLIN);
  }
  catch (std::exception &e) {
    // epoll_ctl
    std::cout << e.what() << std::endl;
  }
}

int Epoll::getEpollFd(void) const 
{
  return _epollFd; 
}

int Epoll::getEvent(int i) const
{
	return _events[i].events; 
}

int Epoll::getReadyFd(void) const
{
	return _readyFd;
}

void Epoll::addFd(int fd, int flags)
{
  struct epoll_event event;

  event.events = flags;
  event.data.fd = fd;
  if (epoll_ctl(_epollFd, EPOLL_CTL_ADD, fd, &event) == -1)
    throw std::exception();
}

void Epoll::wait(void)
{
  _readyFd = epoll_wait(_epollFd, _events, MAX_EVENTS, -1);
  if (_readyFd == -1)
    throw std::exception();
}
