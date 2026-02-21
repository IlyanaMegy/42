/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:19:00 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 19:02:09 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>

# include "./includes/structures.h"
# include "./includes/clist.h"
# include "./includes/memory.h"
# include "./includes/ctype.h"
# include "./includes/args_handler.h"
# include "./includes/linked_list.h"
# include "./includes/garbadge.h"
# include "./includes/string.h"
# include "./includes/utils.h"
# include "./includes/mutex_handler.h"

void			ft_parser(void);
int				ft_populate_philo(void);
void			ft_create_thread_philo(void);
void			ft_join_thread_philo(void);
t_clist			*ft_get_philo_clist_addr(t_clist *p_philo_clst);
t_philo			*ft_get_philo_by_index(int index);
void			ft_invert_distribution(void);

void			set_one_philo_is_death_to_true(t_data *data);
void			set_timestamp(t_philo *phil, t_timestamp *rf, t_timestamp bse);
int				is_one_philo_has_died(void);
void			ft_set_estimated_thinking_time(void);
int				is_end_of_dinner(t_philo *philo);
void			set_launch_timestamp(t_philo *philo);
void			check_death_before_action(t_philo *philo, int action_type);
void			ft_take_fork_priority(void *element, t_philo *philo);
void			drop_mutex_taken(t_philo *philo);
void			all_philo_dead_instant(void);
void			*alone_philo_routine(void *element);

void			ft_taking_fork(void *element);
void			ft_release_mutex(t_fork *hand);
void			ft_hold_mutex(t_fork *hand);
void			ft_sleeping(void *element);
void			ft_is_died(void *element);
void			ft_eating(void *element);
void			ft_thinking(void *element);
void			ft_print_philo_struct(void *element);
int				ft_create_forks(void);
void			ft_destroy_forks(void);
int				ft_get_priority_distr(int philo_id);
pthread_mutex_t	*ft_get_mutex(int id);
int				ft_get_idleft_from_philo(int id_philo);
int				ft_get_idright_from_philo(int id_philo);
t_fork			*ft_get_left_fork(int philo_id);
t_fork			*ft_get_right_fork(int id_philo);
pthread_mutex_t	*ft_get_m_writer(void);
pthread_mutex_t	*ft_get_m_death(void);
pthread_mutex_t	*ft_get_m_eat(void);
long int		ft_get_pace_die(void);
long int		ft_get_pace_eat(void);
long int		ft_get_pace_sleep(void);
long int		ft_get_pace_est_think(void);
t_timestamp		ft_add_timestamp(t_timestamp base, u_int64_t ms_added);
void			set_philo_to_death_by_id(t_data *data, int id);
int				safe_quit_philo(void);

#endif
