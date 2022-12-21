/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:28:47 by jnho              #+#    #+#             */
/*   Updated: 2022/12/20 10:59:56 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

#include "./ps_stack/ps_stack.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./ps_greedy/ps_greedy.h"

void    ps_fill_stack(int argc, char **argv, t_ps_stack *ps_stack);
void    confirm_argv(char *arg);
void    confirm_repetition(t_ps_stack ps_stack);
void    error_control(void);

#endif