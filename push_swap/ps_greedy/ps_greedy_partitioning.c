/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:12:53 by jnho              #+#    #+#             */
/*   Updated: 2022/12/23 14:14:49 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

void	ps_greedy_get_pivot(t_ps_stack *ps_stack, int *pivot_a, int *pivot_b)
{
	int				*arr;
	int				idx;
	t_deque_element	*element;

	arr = malloc(sizeof(int) * dq_size(&ps_stack->stack_a));
	if (!arr)
		error_control();
	element = ps_stack->stack_a.rear;
	idx = 0;
	while (element)
	{
		arr[idx] = element->data;
		element = element->front;
		idx++;
	}
	quick_sort(arr, 0, idx - 1);
	*pivot_a = arr[idx / 3];
	*pivot_b = arr[2 * idx / 3];
	free(arr);
}

size_t	ps_greedy_move_a_to_b(t_ps_stack *ps_stack)
{
	size_t	cmd_cnt;
	int		ele[3];

	cmd_cnt = 0;
	while (dq_size(&ps_stack->stack_a) > 3)
	{
		ps_stack_cmd_pb(ps_stack);
		cmd_cnt++;
	}
	while (dq_size(&ps_stack->stack_a) < 3)
	{
		ps_stack_cmd_pa(ps_stack);
		cmd_cnt++;
	}
	ele[0] = ps_stack->stack_a.rear->data;
	ele[1] = ps_stack->stack_a.rear->front->data;
	ele[2] = ps_stack->stack_a.rear->front->front->data;
	cmd_cnt += ps_greedy_sort_three_element(ps_stack, ele);
	return (cmd_cnt);
}

size_t	ps_greedy_partitioning(t_ps_stack *ps_stack, int pivot_a, int pivot_b)
{
	int		size;
	int		rotate_cnt;
	int		data;
	size_t	cmd_cnt;

	size = dq_size(&ps_stack->stack_a);
	rotate_cnt = 0;
	cmd_cnt = 0;
	while (rotate_cnt < size)
	{
		data = ps_stack->stack_a.rear->data;
		if (data <= pivot_a)
		{
			ps_stack_cmd_pb(ps_stack);
			ps_stack_cmd_rb(ps_stack);
			cmd_cnt++;
		}
		else if (pivot_a < data && data <= pivot_b)
			ps_stack_cmd_pb(ps_stack);
		else
			ps_stack_cmd_ra(ps_stack);
		cmd_cnt++;
		rotate_cnt++;
	}
	return (cmd_cnt);
}

size_t	ps_greedy_pivot_partitioning(t_ps_stack *ps_stack)
{
	size_t	cmd_cnt;
	int		pivot_a;
	int		pivot_b;

	ps_greedy_get_pivot(ps_stack, &pivot_a, &pivot_b);
	if (dq_size(&ps_stack->stack_a) == 5)
	{
		ps_stack_cmd_pb(ps_stack);
		ps_stack_cmd_pb(ps_stack);
		cmd_cnt = 2;
		cmd_cnt += ps_greedy_move_a_to_b(ps_stack);
	}
	else
		cmd_cnt = ps_greedy_partitioning(ps_stack, pivot_a, pivot_b);
	cmd_cnt += ps_greedy_move_a_to_b(ps_stack);
	return (cmd_cnt);
}
