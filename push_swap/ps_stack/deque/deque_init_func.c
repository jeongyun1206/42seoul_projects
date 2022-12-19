/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_init_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:00:34 by jnho              #+#    #+#             */
/*   Updated: 2022/12/16 17:37:25 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void    init_deque(t_deque *deque)
{
    deque->head = 0;
    deque->rear = 0;
    deque->element_cnt = 0;   
}

void    delete_deque(t_deque *deque)
{
    t_deque_element *element;

    while (deque->head)
    {
        element = deque->head;
        (deque->head) = (deque->head)->back;
        free(element);
    }
}