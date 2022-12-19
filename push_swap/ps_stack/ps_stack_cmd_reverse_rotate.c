/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:06:48 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 10:17:33 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void ps_stack_cmd_rra(t_ps_stack *ps_stack)
{
    int tmp_data;

    if (dq_size(&(ps_stack->stack_a)) < 2)
        return ;
    tmp_data = dq_pop_front(&(ps_stack->stack_a));
    dq_push_back(&(ps_stack->stack_a), tmp_data);
}

void ps_stack_cmd_rrb(t_ps_stack *ps_stack)
{
    int tmp_data;

    if (dq_size(&(ps_stack->stack_b)) < 2)
        return ;
    tmp_data = dq_pop_front(&(ps_stack->stack_b));
    dq_push_back(&(ps_stack->stack_b), tmp_data);
}

void ps_stack_cmd_rrr(t_ps_stack *ps_stack)
{
    ps_stack_cmd_rra(ps_stack);
    ps_stack_cmd_rrb(ps_stack);
}
