/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:56:41 by jnho              #+#    #+#             */
/*   Updated: 2022/12/15 17:04:18 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_form(va_list ap, char *str, size_t *idx)
{
	int	rtn;

	(*idx)++;
	if (str[*idx] == 'c')
		rtn = ft_printf_c(ap);
	else if (str[*idx] == 's')
		rtn = ft_printf_s(ap);
	else if (str[*idx] == 'p')
		rtn = ft_printf_p(ap);
	else if (str[*idx] == 'd')
		rtn = ft_printf_d(ap);
	else if (str[*idx] == 'i')
		rtn = ft_printf_d(ap);
	else if (str[*idx] == 'u')
		rtn = ft_printf_u(ap);
	else if (str[*idx] == 'x')
		rtn = ft_printf_x(ap);
	else if (str[*idx] == 'X')
		rtn = ft_printf_large_x(ap);
	else if (str[*idx] == '%')
		rtn = write(1, "%%", 1);
	else
		rtn = 0;
	return (rtn);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	char	*str;
	size_t	idx;
	int		len;
	int		tmp;

	str = (char *)arg;
	idx = 0;
	len = 0;
	va_start(ap, arg);
	while (str[idx] && len != -1)
	{
		if (str[idx] == '%')
			tmp = ft_printf_form(ap, str, &idx);
		else
			tmp = write(1, str + idx, 1);
		if (tmp == -1)
			len = tmp;
		else
			len += tmp;
		idx++;
	}
	va_end(ap);
	return (len);
}
