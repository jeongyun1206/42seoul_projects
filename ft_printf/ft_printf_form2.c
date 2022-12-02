/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_form2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:34:20 by jnho              #+#    #+#             */
/*   Updated: 2022/12/02 18:20:13 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	ft_reverse(char *arr, size_t len)
{
	char	tmp;
	size_t	idx;

	idx = 0;
	while (idx < len / 2)
	{
		tmp = arr[idx];
		arr[idx] = arr[len - idx - 1];
		arr[len - idx - 1] = tmp;
		idx++;
	}
}

int	ft_printf_p(va_list ap)
{
	size_t	p;
	int		idx;
	char	hex[18];

	p = va_arg(ap, size_t);
	idx = 0;
	if (!p)
		hex[idx++] = '0';
	while (p)
	{
		hex[idx++] = "0123456789abcdef"[p % 16];
		p /= 16;
	}
	hex[idx++] = 'x';
	hex[idx++] = '0';
	ft_reverse(hex, idx);
	return (write(1, hex, idx));
}

int	ft_printf_x(va_list ap)
{
	unsigned int	p;
	int				idx;
	char			hex[8];

	p = va_arg(ap, unsigned int);
	idx = 0;
	if (!p)
		hex[idx++] = '0';
	while (p)
	{
		hex[idx++] = "0123456789abcdef"[p % 16];
		p /= 16;
	}
	ft_reverse(hex, idx);
	return (write(1, hex, idx));
}

int	ft_printf_large_x(va_list ap)
{
	unsigned int	p;
	int				idx;
	char			hex[8];

	p = va_arg(ap, unsigned int);
	idx = 0;
	if (!p)
		hex[idx++] = '0';
	while (p)
	{
		hex[idx++] = "0123456789ABCDEF"[p % 16];
		p /= 16;
	}
	ft_reverse(hex, idx);
	return (write(1, hex, idx));
}
