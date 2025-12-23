/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:41 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/17 11:15:44 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		search_str(const char *string, int searchedChar);
char	*p_nbr(int nbr);
char	*p_uint(unsigned int n, char format);
int		p_char(char c);
int		p_str(char *str, int *res_l);
int		p_ptr(unsigned long long ptr);

#endif
