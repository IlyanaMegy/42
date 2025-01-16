#include "../inc/Epoll.hpp"
#include <cstddef>
#include <iostream>
#include <sys/epoll.h>

Epoll::~Epoll() { close(_epollFd); }
Epoll::Epoll(const Server &server) {
  // Créer un epoll instance
  this->_epollFd = epoll_create(1);
  if (this->_epollFd == -1) {
    perror("epoll_create1");

    exit(1);
    // return 1;
  }

  // Ajouter le socket serveur à epoll
  try 
  {
    addFD(server.getSocket(), EPOLLIN);
  }
  catch (std::exception &e) 
  {
    // epoll_ctl
    std::cout << e.what() << std::endl;
  }
}

int Epoll::get_epollFd() const { return this->_epollFd; }
struct epoll_event &Epoll::getCurrEvent() { return this->_curr_event; }
struct epoll_event &Epoll::getAllEvents(int i) { return this->_all_events[i]; }
int Epoll::getReadyFd() const{return this->_readyFd; }


void Epoll::addFD(int fd, int flags) {
  struct epoll_event event;

  event.events = flags;
  event.data.fd = fd;
  if (epoll_ctl(this->_epollFd, EPOLL_CTL_ADD, fd, &event) == -1)
    throw std::exception();
}

void Epoll::wait()
{
  this->_readyFd = epoll_wait(_epollFd, _events, MAX_EVENTS, -1);
  if (_readyFd == -1)
    throw std::exception();
}
