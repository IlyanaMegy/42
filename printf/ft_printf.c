
#include "libftprintf.h"

int	is_whitespace(char c)
{
	
	if (c >= 'c' && c < 127)
}

int	check_errors(const char *str)
{
	int	i;
	if (str)
	{
		i = 0;
		while(str)
		{
			if (str[i] == '%')
			{
				if ((str[i + 1] == '%') || is_whitespace(str[i+1]))
					i++;
				else
					return 1;
			}
			i++;
		}
		return 0;
	}
	return 1;
}

int	ft_printf(const char *str, ...)
{
	size_t i;
	if (str && !check_errors(str))
	{
		i = 0;
		while (str[i]) //  && str[i] != 92 && str[i] != 37
		{
			// while(str[i] != '%')
			// {
			// 	write(1, &str[i], 1);
			// 	i++;
			// }
			
			write(1, &str[i], 1);
			i++;
		}
	}
	return (0);
}