/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:20:47 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:34:23 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t				idx;
	unsigned char		*dst_str;
	const unsigned char	*src_str;

	if (!dest && !src)
		return (0);
	idx = 0;
	dst_str = dest;
	src_str = src;
	while (idx < num)
	{
		dst_str[idx] = src_str[idx];
		idx++;
	}
	return (dest);
}
