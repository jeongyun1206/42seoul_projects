/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayongja <sayongja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:30:15 by jnho              #+#    #+#             */
/*   Updated: 2023/03/16 14:34:21 by sayongja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_free_info(t_info *info)
{
    int     idx;
    t_fork  *fork_arr;

    pthread_mutex_destroy(&info->die_mutex);
    pthread_mutex_destroy(&info->print_mutex);
    if (info->thread_arr)
        free(info->thread_arr);
    fork_arr = info->fork_arr;
    if (fork_arr)
    {
        idx = 0;
        while (idx < info->philo_num - 1)
        {
            pthread_mutex_destroy(&fork_arr[idx].fork_mutex);
            idx++;
        }
        free(info->fork_arr);
    }
    return ;
}

int philo_error_control(t_philo *philo_arr, t_info *info)
{
    if (info)
        philo_free_info(info);
    if (philo_arr)
        free(philo_arr);
    write(2, "ERROR\n", 6);
    return (1);
}


int main(int argc, char **argv)
{
    t_info  info;
    t_philo *philo_arr;
    int     idx;

    if (!set_info(argc, argv, &info))
        return (philo_error_control(0, &info));
    philo_arr = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
    if (!philo_arr)
        return (philo_error_control(philo_arr, &info));
    set_philo_arr(philo_arr, &info);
    idx = -1;
    while (++idx < info.philo_num)
        pthread_create(&info.thread_arr[idx], 0, routine, &philo_arr[idx]);
    idx = -1;
    while (++idx < info.philo_num)
        pthread_join(info.thread_arr[idx], 0);
    return (0);
}