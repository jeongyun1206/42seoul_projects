/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:02:52 by jnho              #+#    #+#             */
/*   Updated: 2022/12/20 16:20:18 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define   DEQUE_H

# include   <stdlib.h>

typedef struct  s_deque_element
{
    struct s_deque_element *front;
    struct s_deque_element *back;
    int             data;
}   t_deque_element;

typedef struct s_deque
{
    t_deque_element *head;
    t_deque_element *rear;
    int             element_cnt;
}   t_deque;

void            init_deque(t_deque *deque);
void            delete_deque(t_deque *deque);

int             dq_empty(t_deque *deque);
int             dq_size(t_deque *deque);
int             dq_front(t_deque *deque);
int             dq_back(t_deque *deque);
int             dq_find_element_by_idx(t_deque *deque, int idx, int *element);

t_deque_element *new_deque_element(int data);
void            dq_push_front(t_deque *deque, int data);
void            dq_push_back(t_deque *deque, int data);
int             dq_pop_front(t_deque *deque);
int             dq_pop_back(t_deque *deque);
void            dq_prt(t_deque *deque);

#endif