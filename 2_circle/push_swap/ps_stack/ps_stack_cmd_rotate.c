/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:05:03 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 15:45:44 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_stack_cmd_ra(t_ps_stack *ps_stack)
{
	int	tmp_data;

	if (dq_size(&(ps_stack->stack_a)) < 2)
		return ;
	tmp_data = dq_pop_back(&(ps_stack->stack_a));
	dq_push_front(&(ps_stack->stack_a), tmp_data);
	write(1, "ra\n", 3);
}

void	ps_stack_cmd_rb(t_ps_stack *ps_stack)
{
	int	tmp_data;

	if (dq_size(&(ps_stack->stack_b)) < 2)
		return ;
	tmp_data = dq_pop_back(&(ps_stack->stack_b));
	dq_push_front(&(ps_stack->stack_b), tmp_data);
	write(1, "rb\n", 3);
}

void	ps_stack_cmd_rr(t_ps_stack *ps_stack)
{
	ps_stack_cmd_ra(ps_stack);
	ps_stack_cmd_rb(ps_stack);
	write(1, "rr\n", 3);
}
