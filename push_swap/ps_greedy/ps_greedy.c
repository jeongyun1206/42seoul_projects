/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:19:05 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 14:43:11 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"
#include <stdio.h>

size_t ps_greedy(t_ps_stack *ps_stack)
{
    size_t  cmd_cnt;
    int     **cmd_table;
    
    cmd_cnt = ps_greedy_pivot_partitioning(ps_stack);
    cmd_table = ps_greedy_make_cmd_table(ps_stack);
    while (dq_size(&ps_stack->stack_b))
    {
        ps_greedy_fill_cmd_table(ps_stack, cmd_table);
        cmd_cnt += ps_greedy_move_element(ps_stack, cmd_table);
    }
    return (cmd_cnt);
}

/**
 * table | rb | rrb | ra | rra | pa | total |
 * rear_1|    |     |    |     |    |       |
 * ...
**/