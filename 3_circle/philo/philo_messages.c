/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:59:56 by jnho              #+#    #+#             */
/*   Updated: 2023/03/19 16:10:49 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die_message(t_philo *philo)
{
	struct timeval	cur_time;
	int				passed_time;

	gettimeofday(&cur_time, 0);
	passed_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000;
	passed_time += (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	printf("%d %d died\n", passed_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	philo->info->die_flag = 1;
	pthread_mutex_unlock(&philo->info->die_mutex);
}

void	philo_fork_message(t_philo *philo)
{
	struct timeval	cur_time;
	int				passed_time;

	gettimeofday(&cur_time, 0);
	passed_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000;
	passed_time += (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	printf("%d %d has taken a fork\n", passed_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	philo_eat_message(t_philo *philo)
{
	struct timeval	cur_time;
	int				passed_time;

	gettimeofday(&cur_time, 0);
	passed_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000;
	passed_time += (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	printf("%d %d is eating\n", passed_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	philo_sleep_message(t_philo *philo)
{
	struct timeval	cur_time;
	int				passed_time;

	gettimeofday(&cur_time, 0);
	passed_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000;
	passed_time += (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	printf("%d %d is sleeping\n", passed_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	philo_think_message(t_philo *philo)
{
	struct timeval	cur_time;
	int				passed_time;

	gettimeofday(&cur_time, 0);
	passed_time = (cur_time.tv_sec - philo->info->start_time.tv_sec) * 1000;
	passed_time += (cur_time.tv_usec - philo->info->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->info->print_mutex);
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_flag)
	{
		pthread_mutex_unlock(&philo->info->die_mutex);
		pthread_mutex_unlock(&philo->info->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	printf("%d %d is thinking\n", passed_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
