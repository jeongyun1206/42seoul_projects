/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:33 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 17:20:49 by jnho             ###   ########seoul.kr  */
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

void checker_confirm_sorted(t_ps_stack ps_stack)
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
	ft_printf("OK");
}

void	checker_do_cmd(char *cmd, t_ps_stack *ps_stack)
{
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "sa", 2))
		ps_stack_cmd_sa(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "sb", 2))
		ps_stack_cmd_sb(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "ss", 2))
		ps_stack_cmd_ss(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "pa", 2))
		ps_stack_cmd_pa(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "pb", 2))
		ps_stack_cmd_pb(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "ra", 2))
		ps_stack_cmd_ra(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "rb", 2))
		ps_stack_cmd_rb(&ps_stack);	
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "rr", 2))
		ps_stack_cmd_rr(&ps_stack);	
	if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rra", 3))
		ps_stack_cmd_rra(&ps_stack);	
	if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rrb", 3))
		ps_stack_cmd_rrb(&ps_stack);	
	if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "rrr", 3))
		ps_stack_cmd_rrr(&ps_stack);
}

int	main(int argc, char **argv)
{
	t_ps_stack	ps_stack;
	size_t		cmd_cnt;
	int			ele[4];
	char		*cmd;

	ps_fill_stack(argc, argv, &ps_stack, 1);
	cmd = get_next_line(0);
	while (cmd)
	{
		checker_do_cmd(cmd, &ps_stack);
		free(cmd);
		cmd = get_next_line(0);
	}
	checker_confirm_sorted(ps_stack);
	exit(0);
}