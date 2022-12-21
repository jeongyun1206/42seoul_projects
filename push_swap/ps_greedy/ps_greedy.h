/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:13:56 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 16:05:38 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_GREEDY_H
# define PS_GREEDY_H

# include "../ps_stack/ps_stack.h"
# include "../error_control/error_control.h"

size_t	ps_greedy(t_ps_stack *ps_stack);

void	swap(int *num1, int *num2);
void	quick_sort(int *arr, int start, int end);

void	ps_greedy_get_pivot(t_ps_stack *ps_stack, int *pivot_a, int *pivot_b);
size_t	ps_greedy_move_a_to_b(t_ps_stack *ps_stack);
size_t	ps_greedy_pivot_partitioning(t_ps_stack *ps_stack);

int		**ps_greedy_make_cmd_table(t_ps_stack *ps_stack);
void	ps_greedy_fill_total_table(int **table, t_deque *stack_b, int idx);
void	ps_greedy_fill_cmd_table(t_ps_stack *ps_stack, int **table);

int		ps_greedy_find_smaller_idx(t_deque stack_a, int b_element);
int		ps_greedy_find_bigger_idx(t_deque stack_a, int b_element);
int		ps_greedy_find_location(t_ps_stack *ps_stack, int b_element);
void	ps_greedy_fill_ra_table(int **table, t_ps_stack *ps_stack, int idx);

int		ps_greedy_find_smallest_cmd_idx(t_ps_stack *ps_stack, int **cmd_table);
int		ps_greedy_move_element(t_ps_stack *ps_stack, int **cmd_table);
int		ps_greedy_find_smallest_element_idx(t_ps_stack *ps_stack);
size_t	ps_greedy_move_smallest_element_to_top(t_ps_stack *ps_stack);

#endif
