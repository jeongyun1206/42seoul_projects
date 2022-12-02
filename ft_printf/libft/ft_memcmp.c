/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:46:55 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:33:58 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				idx;

	p2 = ptr2;
	p1 = ptr1;
	idx = 0;
	if (!num)
		return (0);
	while (1)
	{
		if (p1[idx] != p2[idx])
			break ;
		if (num == idx + 1)
			return (0);
		idx++;
	}
	return (p1[idx] - p2[idx]);
}
