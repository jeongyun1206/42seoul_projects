/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:30:15 by jnho              #+#    #+#             */
/*   Updated: 2023/03/08 17:09:41 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int philo_error_control(void)
{
    write(2, "ERROR\n", 6);
    return (1);
}

int main(int argc, char **argv)
{
    t_info  info;
    t_philo *philo_arr;

    if (!set_info(argc, argv, &info))
        return (philo_error_control());
    philo_arr = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
    if (!philo_arr)
        return (philo_error_control());
    set_philo_arr(philo_arr, &info);
    if (!philo_simulation(&info, philo_arr))
        return (philo_error_control());
}