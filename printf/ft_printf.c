/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:53 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 15:52:02 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	err(const char *str)
{
	while (*str)
	{
		if (*str == '%' && (*(str + 1) != '%' && *(str - 1) != '%'))
		{
			if (ft_strchr("csdiupxX", *(str + 1)) == -1)
				return (1);
		}
		str += 2;
	}
	return (0);
}

int	p_char(char c)
{
	return (write(1, &c, 1));
}

int	p_str(char *res, int *res_l)
{
	if (!res)
		res = "(null)";
	while (*res)
	{
		*res_l += p_char(*res);
		res++;
	}
	res = 0;
	return (0);
}

int	print_it(const char *str, va_list p)
{
	int	res_l;

	res_l = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				res_l += p_char((unsigned char)va_arg(p, int));
			else if (*str == 's')
				p_str(va_arg(p, char *), &res_l);
			else if (*str == 'd' || *str == 'i')
				p_str(p_nbr(va_arg(p, int)), &res_l);
			else if (*str == 'u' || *str == 'x' || *str == 'X')
				p_str(p_uint(va_arg(p, unsigned int), *str), &res_l);
			else if (*str == 'p')
				res_l += p_ptr(va_arg(p, unsigned long long));
			else if (*str == '%')
				res_l += write(1, "%", 1);
		}
		else
		{
			write(1, str, 1);
			res_l++;
		}
		str++;
	}
	return (res_l);
}

int	ft_printf(const char *str, ...)
{
	int		output_len;
	va_list	params;

	va_start(params, str);
	output_len = 0;
	if (*str && !err(str))
		output_len = print_it(str, params);
	va_end(params);
	return (output_len);
}
