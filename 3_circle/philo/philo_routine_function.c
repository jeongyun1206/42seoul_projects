/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:38:25 by jnho              #+#    #+#             */
/*   Updated: 2023/04/01 15:47:59 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_get_fork(t_philo *philo)
{
	if (philo->fork_cnt == 0)
	{
		pthread_mutex_lock(&philo->first_fork->fork_mutex);
		if (philo->first_fork->state == AVAIL)
		{
			philo_fork_message(philo);
			philo->first_fork->state = NOT_AVAIL;
			philo->fork_cnt++;
		}
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
	}
	if (philo->fork_cnt == 1)
	{
		pthread_mutex_lock(&philo->second_fork->fork_mutex);
		if (philo->second_fork->state == AVAIL)
		{
			philo_fork_message(philo);
			philo->second_fork->state = NOT_AVAIL;
			philo->fork_cnt++;
		}
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
	}
}

int	philo_think(t_philo *philo)
{
	philo_think_message(philo);
	while (1)
	{
		if (!philo_check_die(philo))
			return (0);
		if (philo->fork_cnt == 2)
			break ;
		else
			philo_get_fork(philo);
		usleep(100);
	}
	philo->cur_state = EAT;
	gettimeofday(&philo->last_eat, 0);
	return (1);
}

int	philo_eat(t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	cur_time;

	philo_eat_message(philo);
	gettimeofday(&start_time, 0);
	while (1)
	{
		gettimeofday(&cur_time, 0);
		if (check_time(start_time, cur_time, philo->info->time_to_eat))
			break ;
		if (!philo_check_die(philo))
			return (0);
		usleep(500);
	}
	pthread_mutex_lock(&philo->first_fork->fork_mutex);
	philo->first_fork->state = AVAIL;
	pthread_mutex_unlock(&philo->first_fork->fork_mutex);
	pthread_mutex_lock(&philo->second_fork->fork_mutex);
	philo->second_fork->state = AVAIL;
	pthread_mutex_unlock(&philo->second_fork->fork_mutex);
	philo->fork_cnt = 0;
	philo->eating_cnt++;
	philo->cur_state = SLEEP;
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	cur_time;

	philo_sleep_message(philo);
	gettimeofday(&start_time, 0);
	while (1)
	{
		gettimeofday(&cur_time, 0);
		if (check_time(start_time, cur_time, philo->info->time_to_sleep))
			break ;
		if (!philo_check_die(philo))
			return (0);
		usleep(500);
	}
	philo->cur_state = THINK;
	usleep(1000);
	return (1);
}
