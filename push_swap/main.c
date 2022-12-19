/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:00:48 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 12:51:26 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "./ps_stack/ps_stack.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_ps_stack  ps_stack;

    if (!ps_fill_stack(argc, argv, &ps_stack))
        return (0);
    ps_bubble_sort(&ps_stack);
    dq_prt(&ps_stack.stack_a);
    dq_prt(&ps_stack.stack_b);
}