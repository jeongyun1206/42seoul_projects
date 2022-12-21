/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:00:48 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 15:47:56 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_stack	ps_stack;
	size_t		cmd_cnt;

	ps_fill_stack(argc, argv, &ps_stack);
	cmd_cnt = ps_greedy(&ps_stack);
}
