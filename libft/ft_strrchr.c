/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:17:39 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 21:26:55 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	idx;

	idx = ft_strlen(str);
	while (idx)
	{
		if ((unsigned char)str[idx] == (unsigned char)ch)
			return ((char *)str + idx);
		idx--;
	}
	if ((unsigned char)str[idx] == (unsigned char)ch)
		return ((char *)str + idx);
	return (0);
}
