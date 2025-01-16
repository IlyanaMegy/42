#include "Socket.hpp"
#include <exception>
#include <sys/socket.h>

Socket::Socket(int port) : _opt(1)
{
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd == -1)
		throw std::exception();

	_addr.sin_family = AF_INET;
 	_addr.sin_port = htons(port);
 	_addr.sin_addr.s_addr = INADDR_ANY;

	_setOptions();

	if (bind(_fd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
		throw std::exception();

}

Socket::~Socket()
{
	close(_fd);
}

void	Socket::_setOptions(void)
{
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &_opt, sizeof(_opt)) < 0)
		throw std::exception();
}