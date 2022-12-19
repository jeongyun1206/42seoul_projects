/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:16:41 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 11:00:49 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void    init_ps_stack(t_ps_stack *ps_stack)
{
    init_deque(&(ps_stack->stack_a));
    init_deque(&(ps_stack->stack_b));
}

void    delete_ps_stack(t_ps_stack *ps_stack)
{
    delete_deque(&(ps_stack->stack_a));
    delete_deque(&(ps_stack->stack_b));
}