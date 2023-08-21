#include "../inc/pushswap.h"

void	check_args(int ac, char **args)
{
	int i;
	int nb;
	size_t start;
    size_t end;
    char *tmp;

	i = 1;
	start = 0;
    end = 0;
	ft_printf("%d\n", ac);
	while (args[i])
	{
        while (end < ft_strlen(args[i]))
        {
            while (*args[i] == ' ')
            {
                start++;
                args[i]++;
            }
            ft_printf("start at %d, end at %d\n", start, end);
            while (*args[i] != ' ')
            {
                end++;
                args[i]++;
            }
            ft_printf("start at %d, end at %d\ns[0]=%c", start, end, args[i][0]);
            tmp = ft_substr(args[i], 0, end+1);
            ft_printf("\"%s\" len = %d\n", tmp, ft_strlen(tmp));
            nb = ft_atoi(tmp);
            if (!nb)
            {
                ft_printf("not a number !\n");
                break ;
            }
            ft_printf("%d", nb);
            start = end;
        }
		
		i++;
	}
}