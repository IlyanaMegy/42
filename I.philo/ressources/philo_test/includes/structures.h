/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:54:21 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 18:58:19 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_action_type
{
	ACTION_DEFAULT,
	ACTION_EAT,
	ACTION_SLEEP,
	ACTION_THINK,
	ACTION_DEATH_TIME,
	MAX_ACTION_TYPE,
}			t_action_type;

typedef enum e_const
{
	LEFT,
	RIGHT,
	TIME_COEF = 1000,
}			t_const;

typedef enum e_av_enum
{
	PROG_NAME,
	NBR_PHILO,
	DEAD_TIME,
	EAT_TIME,
	SLEEP_TIME,
	NBR_OF_EAT
}			t_av_enum;

typedef struct s_timestamp
{
	u_int64_t	usec;
	u_int64_t	msec;
}				t_timestamp;

typedef struct s_fork
{
	int				id;
	int				taken;
	int				thread_id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_pace
{
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	nbr_each_must_eat;
}				t_pace;

typedef struct s_philo
{
	int				id;
	long int		nbr_of_eat;
	pthread_t		thread_id;
	t_fork			*left_hand;
	int				left_fork_taken;
	t_fork			*right_hand;
	int				right_fork_taken;
	t_timestamp		last_launch_time;
	t_timestamp		next_death_time;
}				t_philo;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_clist
{
	int				is_first;
	int				is_last;
	void			*content;
	struct s_clist	*next;
	struct s_clist	*previous;
}				t_clist;

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**envp;
}				t_args;

typedef struct s_flag
{
	char	count_nbr_must_eat_activated;
	char	error_args;
	char	error;
}				t_flag;

/**
 * Descriptionof the structure
 * args (t_args) this is the args from the main function
 * garbadge (t_list) this is the list for the ft_malloc function
 * nbr_of_philo is explicit
 * philosopher concern the thread instance
 * pace is a struct to have the tempo of the program
 * flag is setted for error and the flag of count nbr eat activation
 * program_started is 
 * 	the timestamp before the thread start | avoid timeout for start the thread 
 * fork is the array for all fork, the philo using it with  accessors
 * m_* is mutex
 * 
 */
typedef struct s_data
{
	t_args			args;
	t_list			*garbadge;
	long int		nbr_of_philo;
	t_clist			*philosopher;
	t_pace			pace;
	t_flag			flag;
	t_timestamp		program_started;
	int				one_philo_is_dead;
	t_fork			*forks;
	pthread_mutex_t	*m_writer;
	pthread_mutex_t	*m_death;
	pthread_mutex_t	*m_lock_check;
	long int		est_time_to_think;
}				t_data;

#endif