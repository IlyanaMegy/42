#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 15

class Server
{
    private:
        int _port;
        struct sockaddr_in _sockAddr;
        // int _socket;
    public:
        Server();
        ~Server();
        int _socket;
};


// Sockets
// HTTP request
// HTTP response
// CGI