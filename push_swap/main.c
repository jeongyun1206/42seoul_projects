/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:00:48 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 17:00:41 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "./ps_stack/ps_stack.h"
#include "push_swap.h"

void    error_control(void)
{
    write(2, "error\n", 6);
    exit(1);
}

int main(int argc, char **argv)
{
    t_ps_stack  ps_stack;
    size_t      cmd_cnt;

    ps_fill_stack(argc, argv, &ps_stack);
    cmd_cnt = ps_greedy(&ps_stack);
    dq_prt(&ps_stack.stack_a);
    dq_prt(&ps_stack.stack_b);
}