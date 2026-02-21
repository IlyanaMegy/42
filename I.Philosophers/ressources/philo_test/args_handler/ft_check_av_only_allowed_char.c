/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av_only_allowed_char.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:02:57 by apayet            #+#    #+#             */
/*   Updated: 2022/08/01 10:50:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief This function check if correct char is entered and if the len lower
 * 	than 10
 * 
 * @return int 
 */
int	ft_check_av_only_allowed_char(void)
{
	int	i;

	i = 1;
	while (i < ft_get_ac())
	{
		if (ft_check_str(ft_get_av()[i]) == 0 || ft_strlen(ft_get_av()[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}
