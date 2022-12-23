/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:28:47 by jnho              #+#    #+#             */
/*   Updated: 2022/12/23 14:00:18 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include "./ps_stack/ps_stack.h"
# include "./error_control/error_control.h"

void	ps_fill_stack(int argc, char **argv, t_ps_stack *ps_stack, int checker);
void	confirm_argv(char *arg);
void	confirm_repetition(t_ps_stack ps_stack);
void	confirm_sorted(t_ps_stack ps_stack);

#endif
