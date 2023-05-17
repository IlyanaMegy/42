/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:06:57 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 18:06:59 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *, ...);
int		ft_strchr(const char *string, int searchedChar);
size_t	ft_strlen(const char *str);
char	*p_nbr(int nbr);
char	*p_uint(unsigned int n, char format);
int		p_char(char c);
int		p_str(char *str, int *res_l);
int		p_ptr(unsigned long long ptr);

#endif
