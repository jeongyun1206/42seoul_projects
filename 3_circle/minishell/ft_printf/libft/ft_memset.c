/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:03:25 by jnho              #+#    #+#             */
/*   Updated: 2023/02/19 16:18:16 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			idx;
	unsigned char	*mem;

	mem = ptr;
	idx = 0;
	while (idx < num)
	{
		mem[idx] = value;
		idx++;
	}
	return (ptr);
}
