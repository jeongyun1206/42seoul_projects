/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_sort_three_element.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:12:04 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 15:28:31 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

void	ps_set_three_ele(int *ele, t_deque stack_a)
{
	ele[0] = stack_a.rear->data;	
	ele[1] = stack_a.rear->front->data;	
	ele[2] = stack_a.rear->front->front->data;
}

size_t	ps_greedy_sort_three_element(t_ps_stack *ps_stack, int *ele)
{
	size_t cmd_cnt;

	cmd_cnt = 0;
	if (ele[0] < ele[1] && ele[0] < ele[2])
		cmd_cnt += ps_greedy_sort_three_element_ele_1(ps_stack, ele);
	else if (ele[0] > ele[1] && ele[0] > ele[2])
		cmd_cnt += ps_greedy_sort_three_element_ele_3(ps_stack, ele);
	else
		cmd_cnt += ps_greedy_sort_three_element_ele_2(ps_stack, ele);
    return (cmd_cnt);
}

size_t  ps_greedy_sort_three_element_ele_1(t_ps_stack *ps_stack, int *ele)
{
	size_t cmd_cnt;

	cmd_cnt = 0;
	if (ele[1] > ele[2])
    {
        ps_stack_cmd_sa(ps_stack);
        ps_stack_cmd_ra(ps_stack);
        cmd_cnt = 2;
    }
    return (cmd_cnt);
}

size_t  ps_greedy_sort_three_element_ele_2(t_ps_stack *ps_stack, int *ele)
{
	size_t cmd_cnt;

	cmd_cnt = 0;
	if (ele[1] > ele[2])
    {
        ps_stack_cmd_rra(ps_stack);
        cmd_cnt = 1;   
    }
	else
    {
        ps_stack_cmd_sa(ps_stack);
        cmd_cnt = 1;
    }
    return (cmd_cnt);
}

size_t  ps_greedy_sort_three_element_ele_3(t_ps_stack *ps_stack, int *ele)
{
	size_t cmd_cnt;

	cmd_cnt = 0;
	if (ele[1] < ele[2])
    {
        ps_stack_cmd_ra(ps_stack);
        cmd_cnt = 1;
    }
	else
    {
        ps_stack_cmd_ra(ps_stack);
        ps_stack_cmd_sa(ps_stack);
        cmd_cnt = 2;
    }
    return (cmd_cnt);
}