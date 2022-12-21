/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_info_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:52 by jnho              #+#    #+#             */
/*   Updated: 2022/12/20 16:17:52 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int dq_empty(t_deque *deque)
{
    return (deque->element_cnt == 0);
}

int dq_size(t_deque *deque)
{
    return (deque->element_cnt);
}

int dq_front(t_deque *deque)
{
    if (dq_empty(deque))
        return (-1);
    return (deque->head->data);
}

int dq_back(t_deque *deque)
{
    if (dq_empty(deque))
        return (-1);
    return (deque->rear->data);
}

int dq_find_element_by_idx(t_deque *deque, int idx, int *element)
{
    t_deque_element *deque_element;
    int             cur_idx;

    if (dq_empty(deque))
        return (0);
    deque_element = deque->rear;
    cur_idx = 0;
    while (deque_element)
    {
        if (idx == cur_idx)
        {
            *element = deque_element->data;
            return (1);
        }
        deque_element = deque_element->front;
        cur_idx++;
    }
    return (0);
}