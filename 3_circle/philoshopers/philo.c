/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:10:27 by jnho              #+#    #+#             */
/*   Updated: 2023/03/08 19:07:39 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_simulation(t_info *info, t_philo *philo_arr)
{
    int idx;

    idx = 0;
    while (idx < info->philo_num)
    {
        pthread_create(info->thread_arr[idx]);
    }
}