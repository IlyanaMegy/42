/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:43 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 11:15:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** Structures
*/
typedef struct s_input
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				num_of_times_ate;
	long long		time_to_die;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_main;

/*
** Functions
*/
// check_args.c
int					check_args(int ac, char **av, t_main *main);

// init_philo_struct.c
int					init_philos(t_main *main);

// init_fork_struct.c


// utils.c
void				exit_handler(char *msg);
int					p_atoi(char *str);
void				philo_free(t_main *main);

#endif
