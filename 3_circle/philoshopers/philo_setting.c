/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:33:03 by jnho              #+#    #+#             */
/*   Updated: 2023/03/12 14:53:02 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int set_info_atoi(char *arg)
{
    int idx;
    int rtn;

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

int set_argv_info(int argc, char **argv, t_info *info)
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

int set_info(int argc, char **argv, t_info *info)
{
    int idx;

    if (!set_argv_info(argc, argv, info))
        return (0);
    if (gettimeofday(&info->start_time, 0) == -1)
        return (0);
    pthread_mutex_init(&info->die_mutex, 0);
    pthread_mutex_init(&info->print_mutex, 0);
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

void    set_philo_arr(t_philo *philo_arr, t_info *info)
{
    int idx;
    int l_fork_idx;
    int r_fork_idx;

    idx = 0;
    while (idx < info->philo_num)
    {
        philo_arr[idx].info = info;
        philo_arr[idx].philo_id = idx + 1;
        if (idx == 0)
            l_fork_idx = info->philo_num - 1;
        else
            l_fork_idx = idx - 1;
        r_fork_idx = idx;
        if (philo_arr[idx].philo_id % 2)
            philo_arr[idx].first_fork = &info->fork_arr[l_fork_idx];
        else
            philo_arr[idx].first_fork = &info->fork_arr[r_fork_idx];
        if (philo_arr[idx].philo_id % 2)
            philo_arr[idx].second_fork = &info->fork_arr[r_fork_idx];
        else
            philo_arr[idx].second_fork = &info->fork_arr[l_fork_idx];
        philo_arr[idx].fork_cnt = 0;
        philo_arr[idx].eating_cnt = 0;
        philo_arr[idx].last_eat = info->start_time;
        philo_arr[idx].cur_state = THINK;
        idx++;
    }
}