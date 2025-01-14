#include "../inc/Server.hpp"

#define FILE "configs/default.conf"

int main(int ac, char **av)
{
    std::string		config;
    if (ac <= 2 )
    {
        try
        {
            // Parse with default conf OR av[1]
            config = (ac == 1 ? FILE : av[1]);

            // Check and read config file
                // define if path is file, folder or something else
                // check if the file exists and accessible
                // read file, check if empty
                // remove comments and spaces
                // split servers ?
                // create server
                // check servers

            // Setup servers on ports specified in the config file

            // Run servers
                /**
                 * Runs main loop that goes through all file descriptors from 0 till the biggest fd in the set.
                 * - check file descriptors returend from select():
                 *      if server fd --> accept new client
                 *      if client fd in read_set --> read message from client
                 *      if client fd in write_set:
                 *          1- If it's a CGI response and Body still not sent to CGI child process --> Send request body to CGI child process.
                 *          2- If it's a CGI response and Body was sent to CGI child process --> Read outupt from CGI child process.
                 *          3- If it's a normal response --> Send response to client.
                 * - servers and clients sockets will be added to _recv_set_pool initially,
                 *   after that, when a request is fully parsed, socket will be moved to _write_set_pool
                 */
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
		return (std::cerr << "usage: ./webserv <path to configuration file> or just ./webserv" << std::endl, 1);

    // Server server;
    // char buff[BUFFER_SIZE];

    // int client_socket;
    // while (1)
    // {
    //     std::cout << "start" << std::endl;
    //     listen(server._socket, 5);
    //     std::cout << "listening..." << std::endl;
    //     client_socket = accept(server._socket, NULL, NULL);
    //     std::cout << "client accepted !" << std::endl;

    //     // verif if -1

    //     while (1)
    //     {
    //         // HTTP requests
    //         ssize_t res = recv(client_socket, buff, BUFFER_SIZE - 1, 0);
    //         if (res != -1)
    //         {
    //             // HTTP response
    //             std::cout << "hi4" << std::endl;
    //             if (send(client_socket, buff, BUFFER_SIZE, 0) == -1)
    //             {
    //                 // error
    //             }
    //         }
    //         std::cout << "hi5" << std::endl;
    //     }
    // }
    // std::cout<< "here" << std::endl;
    return 0;
}

