/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:26:54 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 13:38:17 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int confirm_argv(char *arg)
{
    size_t  idx;

    idx = 0;
    if (arg[idx] == '-')
        idx++;
    while (arg[idx])
    {
        if (arg[idx] < '0' || '9' < arg[idx])
            return (0);
        idx++;
    }
    return (1);
}

int ps_fill_stack(int argc, char **argv, t_ps_stack *ps_stack)
{
    int arg_idx;

    arg_idx = 1;
    init_ps_stack(ps_stack);
    while (arg_idx < argc)
    {
        if (!confirm_argv(argv[arg_idx]))
        {
            delete_ps_stack(ps_stack);
            ft_printf("error\n");
            return (0);
        }
        dq_push_front(&(ps_stack->stack_a), ft_atoi(argv[arg_idx]));
        arg_idx++;
    }
    return (1);
}
