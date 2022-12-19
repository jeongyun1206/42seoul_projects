/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_info_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:52 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 10:30:24 by jnho             ###   ########seoul.kr  */
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