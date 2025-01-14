#include "../inc/Server.hpp"

int main(void)
{
    Server server;
    char buff[BUFFER_SIZE];

    int client_socket;
    while (1)
    {
        std::cout << "1_ start" << std::endl;
        listen(server._socket, 5);
        std::cout << "2_ listening..." << std::endl;
        client_socket = accept(server._socket, NULL, NULL);
        std::cout << "3_ accepted !" << std::endl;

        // verif if -1

        while (1)
        {
            // HTTP requests
            ssize_t res = recv(client_socket, buff, BUFFER_SIZE - 1, 0);
            if (res != -1)
            {
                // HTTP response
                std::cout << "4_ " << std::endl;
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

