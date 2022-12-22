/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_sort_four_element.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:36:47 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 15:37:00 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

size_t ps_greedy_sort_four_element(t_ps_stack *ps_stack, int *ele)
{
    int smallest_idx;
    size_t cmd_cnt;

    smallest_idx = ps_greedy_find_smallest_element_idx(ps_stack);
    if (smallest_idx == 3)
    {
        ps_stack_cmd_rra(ps_stack);
        cmd_cnt = 3;
    }
    else
    {
        cmd_cnt = smallest_idx + 2;
        while (smallest_idx)
        {
            ps_stack_cmd_ra(ps_stack);
            smallest_idx--;
        }
    }
    ps_stack_cmd_pb(ps_stack);
    ps_set_three_ele(ele, ps_stack->stack_a);
    cmd_cnt += ps_greedy_sort_three_element(ps_stack, ele);
    ps_stack_cmd_pa(ps_stack);
    return (cmd_cnt);
}