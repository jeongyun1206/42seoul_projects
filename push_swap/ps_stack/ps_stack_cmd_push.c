/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:47:17 by jnho              #+#    #+#             */
/*   Updated: 2022/12/16 18:03:29 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void ps_stack_cmd_pa(t_ps_stack *ps_stack)
{
    int b_data;

    if (dq_empty(&(ps_stack->stack_b)))
        return ;
    b_data = dq_pop_back(&(ps_stack->stack_b));
    dq_push_back(&(ps_stack->stack_a), b_data);
}

void ps_stack_cmd_pb(t_ps_stack *ps_stack)
{
    int a_data;

    if (dq_empty(&(ps_stack->stack_a)))
        return ;
    a_data = dq_pop_back(&(ps_stack->stack_a));
    dq_push_back(&(ps_stack->stack_b), a_data);
}