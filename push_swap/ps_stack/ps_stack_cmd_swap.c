/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:42:07 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 11:00:52 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void ps_stack_cmd_sa(t_ps_stack *ps_stack)
{
    int tmp_data_front;
    int tmp_data_back;
    
    if (dq_size(&(ps_stack->stack_a)) < 2)
        return ;
    tmp_data_front = dq_pop_back(&(ps_stack->stack_a));
    tmp_data_back = dq_pop_back(&(ps_stack->stack_a));
    dq_push_back(&(ps_stack->stack_a), tmp_data_front);
    dq_push_back(&(ps_stack->stack_a), tmp_data_back);
}

void ps_stack_cmd_sb(t_ps_stack *ps_stack)
{
    int tmp_data_front;
    int tmp_data_back;
    
    if (dq_size(&(ps_stack->stack_b)) < 2)
        return ;
    tmp_data_front = dq_pop_back(&(ps_stack->stack_b));
    tmp_data_back = dq_pop_back(&(ps_stack->stack_b));
    dq_push_back(&(ps_stack->stack_b), tmp_data_front);
    dq_push_back(&(ps_stack->stack_b), tmp_data_back);
}

void ps_stack_cmd_ss(t_ps_stack *ps_stack)
{
    ps_stack_cmd_sa(ps_stack);
    ps_stack_cmd_sb(ps_stack);
}