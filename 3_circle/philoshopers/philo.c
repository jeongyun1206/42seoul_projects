/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:30:15 by jnho              #+#    #+#             */
/*   Updated: 2023/03/12 17:17:43 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_error_control(t_philo *philo_arr)
{
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
        return (philo_error_control(0));
    philo_arr = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
    if (!philo_arr)
        return (philo_error_control(philo_arr));
    set_philo_arr(philo_arr, &info);
    idx = -1;
    while (++idx < info.philo_num)
        pthread_create(&info.thread_arr[idx], 0, routine, &philo_arr[idx]);
    idx = -1;
    while (++idx < info.philo_num)
        pthread_join(info.thread_arr[idx], 0);
    return (0);
}