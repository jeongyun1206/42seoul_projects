/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:00:48 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 17:06:31 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "./ps_greedy/ps_greedy.h"

int	main(int argc, char **argv)
{
	t_ps_stack	ps_stack;
	size_t		cmd_cnt;
	int			ele[4];

	ps_fill_stack(argc, argv, &ps_stack, 0);
	if (dq_size(&ps_stack.stack_a) == 1)
		exit(0);
	if (dq_size(&ps_stack.stack_a) == 2)
	{
		if (ps_stack.stack_a.rear->data > ps_stack.stack_a.head->data)
			ps_stack_cmd_sa(&ps_stack);
	}
	else if (dq_size(&ps_stack.stack_a) == 3)
	{
		ps_set_three_ele(ele, ps_stack.stack_a);
		cmd_cnt = ps_greedy_sort_three_element(&ps_stack, ele);
	}
	else if (dq_size(&ps_stack.stack_a) == 4)
	{
		cmd_cnt = ps_greedy_sort_four_element(&ps_stack, ele);
	}
	else
		cmd_cnt = ps_greedy(&ps_stack);
	exit(0);
}
