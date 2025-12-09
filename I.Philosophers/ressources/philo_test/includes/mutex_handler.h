/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:53:24 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:46:14 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_HANDLER_H
# define MUTEX_HANDLER_H

int		ft_create_mutex_printer(void);
int		ft_create_mutex_lock_check(void);
void	ft_destroy_all_mutex(void);
int		ft_create_mutex_death(void);
int		ft_create_mutex_eat(void);

int		ft_create_all_mutex(void);

#endif