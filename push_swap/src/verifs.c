#include "../inc/pushswap.h"

void	check_args(char **args)
{
	int i;
	size_t start;
	size_t end;
	char *tmp;

	i = 1;
	while (args[i])
	{
		start = 0;
		end = 0;
		while (end < ft_strlen(args[i]))
		{
			while (args[i][start] == ' ')
				start++;
			end = start;
			while (args[i][end] != ' ')
				end++;
			tmp = ft_substr(args[i], start, end - start);
			if (!ft_strlen(tmp))
				break ;
			else if (!ft_atoi(tmp))
				if (!(ft_strlen(tmp) == 1 && tmp[0] == '0'))
					return ;
			start = end;
			ft_printf("---------\n%d\n\n", ft_atoi(tmp));
		}
		i++;
	}
}