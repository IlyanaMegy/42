/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:36:47 by apayet            #+#    #+#             */
/*   Updated: 2022/06/09 21:13:37 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_timestamp	ft_add_timestamp(t_timestamp base, u_int64_t ms_added)
{
	base.msec = base.msec + ms_added;
	base.usec = base.msec * 1000;
	return (base);
}
