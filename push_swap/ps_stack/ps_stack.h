/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:17:36 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 15:46:09 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define    PS_STACK_H

# include "./deque/deque.h"
# include <unistd.h>

typedef struct s_ps_stack
{
	t_deque	stack_a;
	t_deque	stack_b;
}	t_ps_stack;

void	init_ps_stack(t_ps_stack *ps_stack);
void	delete_ps_stack(t_ps_stack *ps_stack);

void	ps_stack_cmd_pa(t_ps_stack *ps_stack);
void	ps_stack_cmd_pb(t_ps_stack *ps_stack);

void	ps_stack_cmd_sa(t_ps_stack *ps_stack);
void	ps_stack_cmd_sb(t_ps_stack *ps_stack);
void	ps_stack_cmd_ss(t_ps_stack *ps_stack);

void	ps_stack_cmd_ra(t_ps_stack *ps_stack);
void	ps_stack_cmd_rb(t_ps_stack *ps_stack);
void	ps_stack_cmd_rr(t_ps_stack *ps_stack);

void	ps_stack_cmd_rra(t_ps_stack *ps_stack);
void	ps_stack_cmd_rrb(t_ps_stack *ps_stack);
void	ps_stack_cmd_rrr(t_ps_stack *ps_stack);

#endif
