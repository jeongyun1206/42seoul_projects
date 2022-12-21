/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_move_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:58:54 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 13:50:15 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

int ps_greedy_find_smallest_cmd_idx(t_ps_stack *ps_stack, int **cmd_table)
{
    int smallest_cmd_idx;
    int smallest_cmd;
    int search_idx;
    
    smallest_cmd = 2147483647;
    search_idx = 0;
    while (search_idx < dq_size(&ps_stack->stack_b))
    {
        if (cmd_table[search_idx][5] < smallest_cmd)
        {
            smallest_cmd = cmd_table[search_idx][5];
            smallest_cmd_idx = search_idx;
        }
        search_idx++;
    }
    return (smallest_cmd_idx);
}

int ps_greedy_move_element(t_ps_stack *ps_stack, int **cmd_table)
{
    int smallest_cmd_idx;
    int total_cmd_cnt;
    int cmd_idx;
    int cmd_cnt;

    smallest_cmd_idx = ps_greedy_find_smallest_cmd_idx(ps_stack, cmd_table);
    total_cmd_cnt = 0;
    cmd_idx = 0;
    while (cmd_idx < 5)
    {
        cmd_cnt = 0;
        while (cmd_cnt < cmd_table[smallest_cmd_idx][cmd_idx])
        {
            if (cmd_idx == 0)
                ps_stack_cmd_rb(ps_stack);
            else if (cmd_idx == 1)
                ps_stack_cmd_rrb(ps_stack);
            else if (cmd_idx == 2)
                ps_stack_cmd_ra(ps_stack);
            else if (cmd_idx == 3)
                ps_stack_cmd_rra(ps_stack);
            else if (cmd_idx == 4)
                ps_stack_cmd_pa(ps_stack);
            cmd_cnt++;
        }
        total_cmd_cnt += cmd_cnt;
        cmd_idx++;
    }
    return (total_cmd_cnt);
}