/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_print_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:40 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 10:33:10 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>//

void    dq_prt(t_deque *deque)
{    
    t_deque_element *element;

    element = deque->head;
    while (element)
    {
        printf("%d ", element->data);
        element = element->back;
    }
    printf("\n");
}
