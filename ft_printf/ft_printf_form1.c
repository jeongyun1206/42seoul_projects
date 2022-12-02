/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_form1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:37:19 by jnho              #+#    #+#             */
/*   Updated: 2022/12/02 20:28:01 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_printf_c(va_list ap)
{
	int	p;

	p = va_arg(ap, int);
	return (write(1, &p, 1));
}

int	ft_printf_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_printf_d(va_list ap)
{
	int		d;
	int		idx;
	char	num[11];

	d = va_arg(ap, int);
	idx = 0;
	if (!d)
		return (write(1, "0", 1));
	if (d < 0)
		num[idx++] = '-';
	while (d)
	{
		if (d < 0)
			num[idx++] = d % 10 * -1 + '0';
		else
			num[idx++] = d % 10 + '0';
		d /= 10;
	}
	if (num[0] == '-')
		ft_reverse(num + 1, idx - 1);
	else
		ft_reverse(num, idx);
	return (write(1, num, idx));
}

int	ft_printf_u(va_list ap)
{
	unsigned int	d;
	int				idx;
	char			num[11];

	d = va_arg(ap, unsigned int);
	idx = 0;
	if (!d)
		return (write(1, "0", 1));
	while (d)
	{
		num[idx++] = d % 10 + '0';
		d /= 10;
	}
	ft_reverse(num, idx);
	return (write(1, num, idx));
}
