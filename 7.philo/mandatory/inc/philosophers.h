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
typedef struct s_colors
{
	char			*reset;
	char			*red;
	char			*green;
	char			*blue;
	char			*purple;
	char			*pink;
	char			*cyan;
}					t_colors;

typedef struct s_errors
{
	char			*nb_args;
	char			*arg1;
	char			*arg2;
	char			*arg3;
	char			*arg4;
	char			*arg5;
}					t_errors;

typedef struct s_actions
{
	char			*eat;
	char			*sleep;
	char			*think;
	char			*fork;
	char			*die;
}					t_actions;

typedef struct s_input
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_of_times_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				nb_of_times_ate;
	long long		ttd;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_colors		c;
	t_actions		a;
	t_errors		err;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	n_thr;
	pthread_mutex_t	philo_died;
	pthread_mutex_t	*philo_ttd;
	pthread_mutex_t	*philo_ate;
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

// handle_forks.c
int					init_forks(t_main *main);

// threads.c
int					init_threads(t_main *main);
int					destroy_threads(t_main *main);

// life.c
int					philo_words(t_main *main, int id, char *color, char *s);
void				*life(void *arg);
int					do_life(t_main *main, int i);
void				*check_it(void *arg);

// actions.c
int					drop_forks(t_main *main, int i);
int					do_eat(t_main *main, int i);
int					is_dead(t_main *main, int *i);

// time.c
long long			get_time(void);
long long			diff_time(long long t);
void				do_action(long long t);

// utils.c
int					p_atoi(char *str);
void				philo_free(t_main *main);

// style.c
void				set_msg_and_colors(t_main *main);

#endif
