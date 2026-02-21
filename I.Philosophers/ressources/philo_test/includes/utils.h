/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:12:01 by apayet            #+#    #+#             */
/*   Updated: 2022/05/31 18:10:09 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_data		*ft_get_data_addr(t_data *p_data);
long int	ft_atoi(const char *nptr);
t_timestamp	ft_get_timestamp(void);
int			ft_is_pair(int nbr);
void		ft_check_fork_state(void);

#endif