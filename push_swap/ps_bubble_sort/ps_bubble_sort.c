/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:55:03 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 13:23:59 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bubble_sort.h"
#include <stdio.h> //
int ps_bubble_sort(t_ps_stack *ps_stack)
{
    int     cmd_cnt;
    int     rotate_cnt;
    t_deque *stack_a;
    t_deque *stack_b;

    cmd_cnt = 0;
    rotate_cnt = 0;
    stack_a = &(ps_stack->stack_a);
    stack_b = &(ps_stack->stack_b);
    while (1)
    {
        if (rotate_cnt == dq_size(stack_a) - 1)
        {
            rotate_cnt = 0;
            ps_stack_cmd_pb(ps_stack);
            printf("pb ");
        }
        if (dq_size(stack_a) <= 1)
            break;
        if (stack_a->rear->data < stack_a->rear->front->data)
        {
            ps_stack_cmd_sa(ps_stack);
            cmd_cnt++;
            printf("sa ");
        }
        ps_stack_cmd_ra(ps_stack);
        printf("ra ");
        rotate_cnt++;
        cmd_cnt++;
    }
    ps_stack_cmd_pb(ps_stack);
    printf("pb ");
    return (cmd_cnt);
}