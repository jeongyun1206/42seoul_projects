/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:26:32 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:16:55 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			idx;

	p = (unsigned char *)ptr;
	v = value;
	idx = 0;
	while (idx < num)
	{
		if (p[idx] == v)
			return (p + idx);
		idx++;
	}
	return (0);
}
