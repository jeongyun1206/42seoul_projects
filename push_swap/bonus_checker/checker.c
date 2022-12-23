/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:33 by jnho              #+#    #+#             */
/*   Updated: 2022/12/23 15:11:06 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	idx;

	idx = 0;
	if (!num)
		return (0);
	while (idx < num - 1)
	{
		if (!str1[idx] && !str2[idx])
			break ;
		if (str1[idx] != str2[idx])
			break ;
		idx++;
	}
	return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
}

void	checker_confirm_sorted(t_ps_stack ps_stack)
{
	t_deque_element	*element;
	int				data;

	element = ps_stack.stack_a.rear;
	data = element->data;
	while (element)
	{
		if (element->data < data)
		{
			ft_printf("KO\n");
			exit(0);
		}
		data = element->data;
		element = element->front;
	}
	ft_printf("OK\n");
}

void	checker_do_cmd(char *cmd, t_ps_stack *ps_stack, int len)
{
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sa\n", len))
		checker_stack_cmd_sa(ps_stack);
	else if (!ft_strncmp(cmd, "sb", len) || !ft_strncmp(cmd, "sb\n", len))
		checker_stack_cmd_sb(ps_stack);
	else if (!ft_strncmp(cmd, "ss", len) || !ft_strncmp(cmd, "ss\n", len))
		checker_stack_cmd_ss(ps_stack);
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pa\n", len))
		checker_stack_cmd_pa(ps_stack);
	else if (!ft_strncmp(cmd, "pb", len) || !ft_strncmp(cmd, "pb\n", len))
		checker_stack_cmd_pb(ps_stack);
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "ra\n", len))
		checker_stack_cmd_ra(ps_stack);
	else if (!ft_strncmp(cmd, "rb", len) || !ft_strncmp(cmd, "rb\n", len))
		checker_stack_cmd_rb(ps_stack);
	else if (!ft_strncmp(cmd, "rr", len) || !ft_strncmp(cmd, "rr\n", len))
		checker_stack_cmd_rr(ps_stack);
	else if (!ft_strncmp(cmd, "rra", len) ||!ft_strncmp(cmd, "rra\n", len))
		checker_stack_cmd_rra(ps_stack);
	else if (!ft_strncmp(cmd, "rrb", len) ||!ft_strncmp(cmd, "rrb\n", len))
		checker_stack_cmd_rrb(ps_stack);
	else if (!ft_strncmp(cmd, "rrr", len) ||!ft_strncmp(cmd, "rrr\n", len))
		checker_stack_cmd_rrr(ps_stack);
	else
		error_control();
}

int	main(int argc, char **argv)
{
	t_ps_stack	ps_stack;
	char		*cmd;

	ps_fill_stack(argc, argv, &ps_stack, 1);
	cmd = get_next_line(0);
	while (cmd)
	{
		checker_do_cmd(cmd, &ps_stack, ft_strlen(cmd));
		free(cmd);
		cmd = get_next_line(0);
	}
	checker_confirm_sorted(ps_stack);
	exit(0);
}
