/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:10:27 by jnho              #+#    #+#             */
/*   Updated: 2023/03/19 16:11:03 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time(struct timeval s_time, struct timeval c_time, int ch_time)
{
	int	passed_time;

	passed_time = 0;
	passed_time += (c_time.tv_sec - s_time.tv_sec) * 1000;
	passed_time += (c_time.tv_usec - s_time.tv_usec) / 1000;
	if (passed_time >= ch_time)
		return (1);
	return (0);
}

int	philo_check_die(t_philo *philo)
{
	struct timeval	cur_time;

	if (philo->info->cnt_to_end == philo->eating_cnt)
		return (0);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag == 1)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	gettimeofday(&cur_time, 0);
	if (check_time(philo->last_eat, cur_time, philo->info->time_to_die))
	{
		philo_die_message(philo);
		return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->cur_state == THINK)
		{
			if (!philo_think(philo))
				return (0);
		}
		if (philo->cur_state == EAT)
		{
			if (!philo_eat(philo))
				return (0);
		}
		if (philo->cur_state == SLEEP)
		{
			if (!philo_sleep(philo))
				return (0);
		}
	}
}
