/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_cmd_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:47:17 by jnho              #+#    #+#             */
/*   Updated: 2022/12/23 14:48:23 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	checker_stack_cmd_pa(t_ps_stack *_stack)
{
	int	b_data;

	if (dq_empty(&(_stack->stack_b)))
		return ;
	b_data = dq_pop_back(&(_stack->stack_b));
	dq_push_back(&(_stack->stack_a), b_data);
}

void	checker_stack_cmd_pb(t_ps_stack *_stack)
{
	int	a_data;

	if (dq_empty(&(_stack->stack_a)))
		return ;
	a_data = dq_pop_back(&(_stack->stack_a));
	dq_push_back(&(_stack->stack_b), a_data);
}
