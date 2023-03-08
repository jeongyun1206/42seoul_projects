/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:29:15 by jnho              #+#    #+#             */
/*   Updated: 2023/03/08 17:25:28 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

/* philo states code */
#define SLEEP 0
#define THINK 1
#define EAT 2

/* fork status */
#define USING 0
#define NOTUSING 1

typedef struct s_fork
{
    pthread_mutex_t fork_mutex;
    int             state;
}   t_fork;

typedef struct s_info
{
    int             philo_num;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             cnt_to_end;
    struct timeval  start_time;
    int             die_flag;
    pthread_mutex_t info_mutex;
    pthread_mutex_t print_mutex;
    t_fork          *fork_arr;
    pthread_t       *thread_arr;
}   t_info;

typedef struct s_philo
{
    t_info          *info;
    int             philo_id;
    int             l_fork_idx;
    int             r_fork_idx;
    int             fork_cnt;
    int             eating_cnt;
    int             cur_state;
    struct timeval  last_eat;
}   t_philo;



int     set_info(int argc, char **argv, t_info *info);
void    set_philo_arr(t_philo *philo_arr, t_info *info);
int     philo_simulation(t_info *info, t_philo *philo_arr);