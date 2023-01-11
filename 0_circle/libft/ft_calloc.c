/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:15:46 by jnho              #+#    #+#             */
/*   Updated: 2022/11/21 16:00:22 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	size_t			idx;
	unsigned char	*rtn_arr;

	idx = 0;
	rtn_arr = (unsigned char *)malloc(cnt * size);
	if (!rtn_arr)
		return (0);
	while (idx < cnt * size)
	{
		rtn_arr[idx] = 0;
		idx++;
	}
	return ((void *)rtn_arr);
}
