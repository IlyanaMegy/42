#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <netinet/in.h>

class Socket
{
    private:
        int _opt;
    	int _fd;
		struct sockaddr_in _addr;

        void _setOptions(void);

    public:
        Socket(int port);
        ~Socket(void);
        
};

#endif
