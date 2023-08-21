#include "../inc/pushswap.h"

void    check_args(char **args)
{
    int i;

    i = 1;
    while (args[i])
    {
        if (!atoi(args[i]))
            ft_printf("not a number ! : ");
        ft_printf("%s\n", args[i]);
        i++;
    }
}