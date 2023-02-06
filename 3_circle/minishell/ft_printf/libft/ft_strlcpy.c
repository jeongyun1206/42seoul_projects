/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:27:06 by jnho              #+#    #+#             */
/*   Updated: 2022/11/14 13:46:30 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(const void *dest, const void *src, size_t size)
{
	char	*src_arr;
	char	*dest_arr;
	size_t	idx;
	size_t	src_len;

	src_arr = (char *)src;
	dest_arr = (char *)dest;
	idx = 0;
	src_len = 0;
	while (src_arr[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (idx + 1 < size && src_arr[idx])
	{
		dest_arr[idx] = src_arr[idx];
		idx++;
	}
	dest_arr[idx] = '\0';
	return (src_len);
}
