/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:40:20 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:38:27 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_idx;
	size_t	src_idx;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	src_idx = 0;
	dest_idx = dest_len;
	while ((dest_idx < size - 1) && (src[src_idx]))
		dest[dest_idx++] = src[src_idx++];
	dest[dest_idx] = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}
