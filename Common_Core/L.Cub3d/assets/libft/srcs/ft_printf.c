/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:38:12 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/26 17:02:07 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_type(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i = ft_print_char(va_arg(args, int));
	else if (*format == 's')
		i = ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long));
	else if (*format == 'd')
		i = ft_print_int(va_arg(args, int));
	else if (*format == 'i')
		i = ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		i = ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		i = ft_print_hex(va_arg(args, unsigned int), 'a' - 10);
	else if (*format == 'X')
		i = ft_print_hex(va_arg(args, unsigned int), 'A' - 10);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				i += ft_check_type(format, args);
			else if (*format == '%')
				i += ft_print_char('%');
		}
		else
			i += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	*p;

// 	s = "bonjour %c %s %p %d %i %u %x %X %%%% \n";
// 	c = 'a';
// 	p = 0;
// 	printf(s, c, "hello", 123, 10, 15, 25, 12, 12);
// 	printf("%d\n\n", printf(s, c, "hello", 123, 10, 15, 25, 12, 12));

// 	ft_printf(s, c, "hello", 123, 10, 15, 25, 12, 12);
// 	ft_printf("%d\n\n", ft_printf(s, c, "hello", 123, 10, 15, 25, 12, 12));

// 	printf(p, "bla");
// 	printf("%d\n", printf(p, "bla"));
// 	ft_printf(p, "bla");
// 	ft_printf("%d\n\n", ft_printf(p, "bla"));

// 	printf("%s", p);
// 	printf("\n%d\n", printf("%s", p));
// 	ft_printf("%s", p);
// 	ft_printf("\n%d\n\n", ft_printf("%s", p));
// 	return (1);
// }
