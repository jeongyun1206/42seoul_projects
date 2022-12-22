/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:26:54 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 17:05:00 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	confirm_argv(char *arg)
{
	size_t	idx;

	idx = 0;
	if (arg[idx] == '-')
		idx++;
	if (arg[idx] == 0)
		error_control();
	while (arg[idx])
	{
		if (arg[idx] < '0' || '9' < arg[idx])
			error_control();
		idx++;
	}
}

void	confirm_repetition(t_ps_stack ps_stack)
{
	t_deque_element	*element;
	t_deque			*stack_a;
	t_deque_element	*search_element;

	stack_a = &ps_stack.stack_a;
	while (stack_a->head)
	{
		element = stack_a->head;
		if (!stack_a->head->back)
			return ;
		search_element = stack_a->head->back;
		while (search_element)
		{
			if (element->data == search_element->data)
				error_control();
			search_element = search_element->back;
		}
		(stack_a->head) = (stack_a->head)->back;
	}
}

void confirm_sorted(t_ps_stack ps_stack)
{
	t_deque_element	*element;
	int				data;

	element = ps_stack.stack_a.rear;
	data = element->data;
	while (element)
	{
		if (element->data < data)
			return ;
		data = element->data;
		element = element->front;
	}
	exit(1);
}

void	ps_fill_stack(int argc, char **argv, t_ps_stack *ps_stack, int checker)
{
	int	arg_idx;

	if (argc < 2)
		exit(0);
	arg_idx = 1;
	init_ps_stack(ps_stack);
	while (arg_idx < argc)
	{
		confirm_argv(argv[arg_idx]);
		dq_push_front(&(ps_stack->stack_a), ft_atoi(argv[arg_idx]));
		arg_idx++;
	}
	confirm_repetition(*ps_stack);
	if (!checker)
		confirm_sorted(*ps_stack);
}
