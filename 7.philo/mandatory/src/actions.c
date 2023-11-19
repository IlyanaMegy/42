/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:40:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/19 14:40:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (1);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (1);
	main->philo[i].nb_of_times_ate++;
	return (0);
}

int	do_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (1);
	if (philo_words(main, main->philo[i].id, main->c.cyan, main->a.fork))
		return (1);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (1);
	if (philo_words(main, main->philo[i].id, main->c.cyan, main->a.fork))
		return (1);
	if (philo_words(main, main->philo[i].id, main->c.blue, main->a.eat))
		return (1);
	main->philo[i].ttd = get_time();
	do_action(main->input.tte);
	drop_forks(main, i);
	return (0);
}

int	do_sleep(t_main *main, int i)
{
	if (philo_words(main, main->philo[i].id, main->c.purple, main->a.sleep))
		return (1);
	do_action(main->input.tts);
	return (0);
}

int	do_think(t_main *main, int i)
{
	if (philo_words(main, main->philo[i].id, main->c.pink, main->a.think))
		return (1);
	return (0);
}

int	is_dead(t_main *main, int *i)
{
	int t;
	if (*i == main->input.nb_philo)
		*i = 0;
	t = diff_time(main->philo[*i].ttd);
	if (t > main->input.ttd)
	{
		philo_words(main, main->philo[*i].id, main->c.red, main->a.die);
		main->philo_dead = 1;
		return (1);
	}
	i++;
	return (0);
}