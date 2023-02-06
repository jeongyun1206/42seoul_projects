/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:39:42 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:34:53 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_arr;
	const unsigned char	*src_arr;
	size_t				idx;

	dest_arr = (unsigned char *)dest;
	src_arr = (const unsigned char *)src;
	if (!n || (!dest && !src))
		return (dest);
	if (dest > src)
	{
		idx = n;
		while (idx > 0)
		{
			dest_arr[idx - 1] = src_arr[idx - 1];
			idx--;
		}
		return (dest);
	}
	idx = 0;
	while (idx < n)
	{
		dest_arr[idx] = src_arr[idx];
		idx++;
	}
	return (dest);
}
