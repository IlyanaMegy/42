#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include <sys/socket.h>
# include <netinet/in.h>
# include <exception>
# include <string>

# include "Client.hpp"

class Server {
	private:
		int _port;
		Socket	_socket;
		std::map<int, Client> _clients;	

	public:
		Server(int port);
		~Server(void);

		int getSocket(void) const;
		Client  &getClient(int i) const;

		void acceptClient(void);
		void readFrom(int i);
		void send(int fd);
		
		class SocketCreationErrException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
