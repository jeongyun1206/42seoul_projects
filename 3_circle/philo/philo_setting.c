/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:33:03 by jnho              #+#    #+#             */
/*   Updated: 2023/04/01 19:27:11 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_info_atoi(char *arg)
{
	int	idx;
	int	rtn;

	rtn = 0;
	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] < '0' || '9' < arg[idx])
			return (-1);
		rtn *= 10;
		rtn += arg[idx] - '0';
		idx++;
	}
	return (rtn);
}

int	set_argv_info(int argc, char **argv, t_info *info)
{
	if (argc < 4 || 7 < argc)
		return (0);
	info->philo_num = set_info_atoi(argv[1]);
	if (info->philo_num == -1)
		return (0);
	info->time_to_die = set_info_atoi(argv[2]);
	if (info->time_to_die == -1)
		return (0);
	info->time_to_eat = set_info_atoi(argv[3]);
	if (info->time_to_eat == -1)
		return (0);
	info->time_to_sleep = set_info_atoi(argv[4]);
	if (info->time_to_sleep == -1)
		return (0);
	if (argc == 6)
		info->cnt_to_end = set_info_atoi(argv[5]);
	else
		info->cnt_to_end = -1;
	if (argc == 6 && info->cnt_to_end == -1)
		return (0);
	return (1);
}

int	set_info(int argc, char **argv, t_info *info)
{
	int	idx;

	pthread_mutex_init(&info->die_mutex, 0);
	pthread_mutex_init(&info->print_mutex, 0);
	if (argc < 5 || argc > 6)
		return (0);
	if (!set_argv_info(argc, argv, info))
		return (0);
	if (gettimeofday(&info->start_time, 0) == -1)
		return (0);
	info->fork_arr = (t_fork *)malloc(sizeof(t_fork) * info->philo_num);
	if (!info->fork_arr)
		return (0);
	idx = 0;
	while (idx < info->philo_num)
	{
		info->fork_arr[idx].state = AVAIL;
		pthread_mutex_init(&info->fork_arr[idx].fork_mutex, 0);
		idx++;
	}
	info->thread_arr = (pthread_t *)malloc(sizeof(pthread_t) * info->philo_num);
	if (!info->thread_arr)
		return (0);
	return (1);
}

void	set_philo_arr(t_philo *philo_arr, t_info *info)
{
	int	variables[3];

	variables[2] = -1;
	while (++variables[2] < info->philo_num)
	{
		philo_arr[variables[2]].info = info;
		philo_arr[variables[2]].philo_id = variables[2] + 1;
		if (variables[2] == 0)
			variables[0] = info->philo_num - 1;
		else
			variables[0] = variables[2] - 1;
		variables[1] = variables[2];
		if (philo_arr[variables[2]].philo_id % 2)
			philo_arr[variables[2]].first_fork = &info->fork_arr[variables[0]];
		else
			philo_arr[variables[2]].first_fork = &info->fork_arr[variables[1]];
		if (philo_arr[variables[2]].philo_id % 2)
			philo_arr[variables[2]].second_fork = &info->fork_arr[variables[1]];
		else
			philo_arr[variables[2]].second_fork = &info->fork_arr[variables[0]];
		philo_arr[variables[2]].fork_cnt = 0;
		philo_arr[variables[2]].eating_cnt = 0;
		philo_arr[variables[2]].last_eat = info->start_time;
		philo_arr[variables[2]].cur_state = THINK;
	}
}
