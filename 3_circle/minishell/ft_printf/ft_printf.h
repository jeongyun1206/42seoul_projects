/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:57:37 by jnho              #+#    #+#             */
/*   Updated: 2022/12/02 18:20:32 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *arg, ...);
int		ft_printf_form(va_list ap, char *str, size_t *idx);

int		ft_printf_c(va_list ap);
int		ft_printf_s(va_list ap);
int		ft_printf_p(va_list ap);
int		ft_printf_d(va_list ap);
int		ft_printf_u(va_list ap);
int		ft_printf_x(va_list ap);
int		ft_printf_large_x(va_list ap);
void	ft_reverse(char *arr, size_t len);

#endif
