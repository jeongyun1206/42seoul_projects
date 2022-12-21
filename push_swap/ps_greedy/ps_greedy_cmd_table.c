/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_cmd_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:17:47 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 16:06:58 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

int	**ps_greedy_make_cmd_table(t_ps_stack *ps_stack)
{
	int	**cmd_table;
	int	table_idx;
	int	table_size;

	table_size = dq_size(&ps_stack->stack_b);
	cmd_table = (int **)malloc(sizeof(int *) * table_size);
	if (!cmd_table)
		error_control();
	table_idx = 0;
	while (table_idx < table_size)
	{
		cmd_table[table_idx] = (int *)malloc(sizeof(int) * 6);
		if (!cmd_table[table_idx])
			error_control();
		table_idx++;
	}
	return (cmd_table);
}

void	ps_greedy_fill_total_table(int **table, t_deque *stack_b, int idx)
{
	int	cmd_idx;

	table[idx][0] = idx;
	table[idx][1] = dq_size(stack_b) - idx;
	if (table[idx][0] < table[idx][1])
		table[idx][1] = 0;
	else
		table[idx][0] = 0;
	if (table[idx][2] < table[idx][3])
		table[idx][3] = 0;
	else
		table[idx][2] = 0;
	table[idx][4] = 1;
	cmd_idx = 0;
	while (cmd_idx < 5)
		table[idx][5] += table[idx][cmd_idx++];
}

void	ps_greedy_reset_table(t_ps_stack *ps_stack, int **table)
{
	int	t_idx;
	int	idx;

	t_idx = 0;
	while (t_idx < dq_size(&ps_stack->stack_b))
	{
		idx = 0;
		while (idx < 6)
		{
			table[t_idx][idx] = 0;
			idx++;
		}
		t_idx++;
	}
}

void	ps_greedy_fill_cmd_table(t_ps_stack *ps_stack, int **table)
{
	int	idx;

	idx = 0;
	ps_greedy_reset_table(ps_stack, table);
	while (idx < dq_size(&ps_stack->stack_b))
	{
		ps_greedy_fill_ra_table(table, ps_stack, idx);
		ps_greedy_fill_total_table(table, &ps_stack->stack_b, idx);
		idx++;
	}
}
