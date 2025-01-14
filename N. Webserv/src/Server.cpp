#include "../inc/Server.hpp"
Server::Server()
{
    int opt = 1;
    // create socket
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1)
        // return err

    _sockAddr.sin_family = AF_INET;
    _sockAddr.sin_port = htons(9001);
    _sockAddr.sin_addr.s_addr= INADDR_ANY;
    setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bind(_socket, (struct sockaddr*)&_sockAddr, sizeof(_sockAddr));
    std::cout << "1_ start" << std::endl;
    listen(_socket, 5);
}

Server::~Server(){}

const char *Server::SocketCreationErrException::what() const throw()
{
	return ("[SERVER]_ Error while creating socket.");
}
