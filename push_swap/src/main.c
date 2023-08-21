#include "../inc/pushswap.h"

int main(int ac, char **av)
{
    if (ac > 1)
        check_args(av);
    else
        ft_printf("Error\n");
    return 0;
}