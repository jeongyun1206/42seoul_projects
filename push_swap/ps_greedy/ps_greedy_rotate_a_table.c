/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_rotate_a_table.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:39:57 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 15:01:59 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

int ps_greedy_find_smaller_idx(t_deque stack_a, int b_element)
{
    int     smaller_element_idx;
    int     smaller_element;
    int     cur_stack_idx;
    t_deque_element *a_element;

    a_element = stack_a.rear;
    smaller_element = -2147483648;
    cur_stack_idx = 0;
    while (a_element)
    {
        if (a_element->data > smaller_element && a_element->data < b_element)
        {
            smaller_element = a_element->data;
            smaller_element_idx = cur_stack_idx;
        }
        a_element = a_element->front;
        cur_stack_idx++;
    }
    return (smaller_element_idx); 
}

int ps_greedy_find_bigger_idx(t_deque stack_a, int b_element)
{
    int     bigger_element_idx;
    int     bigger_element;
    int     cur_stack_idx;
    t_deque_element *a_element;

    a_element = stack_a.rear;
    bigger_element = 2147483647;
    cur_stack_idx = 0;
    while (a_element)
    {
        if (a_element->data < bigger_element && a_element->data > b_element)
        {
            bigger_element = a_element->data;
            bigger_element_idx = cur_stack_idx;
        }
        a_element = a_element->front;
        cur_stack_idx++;
    }
    return (bigger_element_idx); 
}

int ps_greedy_find_location(t_ps_stack *ps_stack, int b_element)
{
    int smaller_idx;
    int bigger_idx;

    smaller_idx = ps_greedy_find_smaller_idx(ps_stack->stack_a, b_element);    
    bigger_idx = ps_greedy_find_bigger_idx(ps_stack->stack_a, b_element);
    if (smaller_idx == -1)
        return (bigger_idx);
    if (bigger_idx == -1)
        return (smaller_idx + 1);
    return (bigger_idx);
}

void    ps_greedy_fill_ra_table(int **table, t_ps_stack *ps_stack, int idx)
{
    int b_element;
    int location_idx;

    if (ps_stack->stack_a.rear == ps_stack->stack_a.head)
    {
        table[idx][2] = 0;
        table[idx][3] = 0;
        return ;
    }
    dq_find_element_by_idx(&ps_stack->stack_b, idx, &b_element);
    location_idx = ps_greedy_find_location(ps_stack, b_element);
    table[idx][3] = dq_size(&ps_stack->stack_a) - location_idx;
    table[idx][2] = location_idx;
}

/**
 * table | rb | rrb | ra | rra | pa | total |
 * rear_1|    |     |    |     |    |       |
 * ...
**/
