/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_before_action.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:15:32 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 15:17:37 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_only_if_not_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(ft_get_m_death());
	if (data->one_philo_is_dead == 0)
	{
		pthread_mutex_unlock(ft_get_m_death());
		ft_is_died((void *)philo);
	}
	else
		pthread_mutex_unlock(ft_get_m_death());
}

/**
 * @brief 
 * 
 * @param philo 
 * @param timestamp 
 * @param base 
 */
static void	act_eat(t_philo *philo, t_timestamp *timestamp, t_timestamp base)
{
	t_data	*data;

	data = ft_get_data_addr((void *)0);
	if (timestamp[ACTION_DEATH_TIME].msec <= timestamp[ACTION_EAT].msec)
	{
		usleep((timestamp[ACTION_DEATH_TIME].msec - base.msec) * TIME_COEF);
		print_only_if_not_dead(data, philo);
		set_one_philo_is_death_to_true(data);
	}
	else
		usleep(ft_get_pace_eat());
}

static void	act_sleep(t_philo *philo, t_timestamp *timestamp, t_timestamp base)
{
	t_data	*data;

	data = ft_get_data_addr((void *)0);
	if (timestamp[ACTION_DEATH_TIME].msec <= timestamp[ACTION_SLEEP].msec)
	{
		usleep((timestamp[ACTION_DEATH_TIME].msec - base.msec) * TIME_COEF);
		print_only_if_not_dead(data, philo);
		set_one_philo_is_death_to_true(data);
	}
	else
		usleep(ft_get_pace_sleep());
}

static void	act_think(t_philo *philo, t_timestamp *timestamp)
{
	t_data		*data;
	long int	tempo;

	(void)tempo;
	(void)timestamp;
	data = ft_get_data_addr((void *)0);
	usleep(ft_get_pace_est_think());
	if (ft_get_pace_est_think() != 0 \
		&& timestamp[ACTION_DEATH_TIME].msec <= timestamp[ACTION_THINK].msec)
	{
		print_only_if_not_dead(data, philo);
		set_one_philo_is_death_to_true(data);
	}
}

/**
 * @brief this function check if the next death time
 *  is outdated from the timestamp
 * 	
 * 	if action != ACTION_DEFAULT the check is called before a sleep
 * 
 * @param philo
 * @param action_type
 * @return int return a boolean value
 */
void	check_death_before_action(t_philo *philo, int action_type)
{
	t_data				*data;
	t_timestamp			timestamp[MAX_ACTION_TYPE];
	t_timestamp			base;

	data = ft_get_data_addr((t_data *)0);
	if (is_one_philo_has_died())
		return ;
	base = ft_get_timestamp();
	if (base.msec > philo->next_death_time.msec)
	{
		print_only_if_not_dead(data, philo);
		set_one_philo_is_death_to_true(data);
	}
	if (ACTION_DEFAULT == action_type)
		return ;
	set_timestamp(philo, timestamp, base);
	if (ACTION_EAT == action_type)
		act_eat(philo, timestamp, base);
	if (ACTION_SLEEP == action_type)
		act_sleep(philo, timestamp, base);
	if (ACTION_THINK == action_type)
		act_think(philo, timestamp);
}
