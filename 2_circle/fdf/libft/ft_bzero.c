/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:20:36 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:32:59 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t			idx;
	unsigned char	*mem;

	mem = ptr;
	idx = 0;
	while (idx < num)
	{
		mem[idx] = 0;
		idx++;
	}
	return ;
}
