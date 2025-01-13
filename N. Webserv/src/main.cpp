#include "../inc/Server.hpp"

int main(void)
{
    Server server;
    char buff[BUFFER_SIZE];

    int client_socket;
    while (1)
    {
        std::cout << "hi1" << std::endl;
        listen(server._socket, 5);
        std::cout << "hi2" << std::endl;
        client_socket = accept(server._socket, NULL, NULL);
        std::cout << "hi3 accepted" << std::endl;

        // verif if -1

        while (1)
        {
            // HTTP requests
            ssize_t res = recv(client_socket, buff, BUFFER_SIZE - 1, 0);
            if (res != -1)
            {
                // HTTP response
                std::cout << "hi4" << std::endl;
                if (send(client_socket, buff, BUFFER_SIZE, 0) == -1)
                {
                    // error
                }
            }
            std::cout << "hi5" << std::endl;
        }
    }
    std::cout<< "here" << std::endl;
    return 0;
}

