/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:29:15 by jnho              #+#    #+#             */
/*   Updated: 2023/03/12 14:52:54 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

/* philo states code */
#define SLEEP 0
#define THINK 1
#define EAT 2

/* fork status */
#define NOT_AVAIL 0
#define AVAIL 1

/* philo message type */
#define FORK_MESSAGE 0
#define EAT_MESSAGE 1
#define SLEEP_MESSAGE 2
#define THINK_MESSAGE 3
#define DIE_MESSAGE 4

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
    pthread_mutex_t die_mutex;
    pthread_mutex_t print_mutex;
    t_fork          *fork_arr;
    pthread_t       *thread_arr;
}   t_info;

typedef struct s_philo
{
    t_info          *info;
    int             philo_id;
    t_fork          *first_fork;
    t_fork          *second_fork;
    int             fork_cnt;
    int             eating_cnt;
    int             cur_state;
    struct timeval  last_eat;
    struct timeval  start_eat;
}   t_philo;

void    philo_message(int type, t_philo *philo);
int     set_info(int argc, char **argv, t_info *info);
void    set_philo_arr(t_philo *philo_arr, t_info *info);
int     philo_simulation(t_info *info, t_philo *philo_arr);
void    *routine(void *arg);
int check_time(struct timeval s_time, struct timeval c_time, int check_time);
int philo_check_die(t_philo *philo);
int philo_think(t_philo *philo);
int philo_sleep(t_philo *philo);
int philo_eat(t_philo *philo);