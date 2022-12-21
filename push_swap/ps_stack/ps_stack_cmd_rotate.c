/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:05:03 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 16:15:12 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void ps_stack_cmd_ra(t_ps_stack *ps_stack)
{
    int tmp_data;

    if (dq_size(&(ps_stack->stack_a)) < 2)
        return ;
    tmp_data = dq_pop_back(&(ps_stack->stack_a));
    dq_push_front(&(ps_stack->stack_a), tmp_data);
    ft_printf("ra\n");
}

void ps_stack_cmd_rb(t_ps_stack *ps_stack)
{
    int tmp_data;

    if (dq_size(&(ps_stack->stack_b)) < 2)
        return ;
    tmp_data = dq_pop_back(&(ps_stack->stack_b));
    dq_push_front(&(ps_stack->stack_b), tmp_data);
    ft_printf("rb\n");
}

void ps_stack_cmd_rr(t_ps_stack *ps_stack)
{
    ps_stack_cmd_ra(ps_stack);
    ps_stack_cmd_rb(ps_stack);
    ft_printf("rr\n");
}
