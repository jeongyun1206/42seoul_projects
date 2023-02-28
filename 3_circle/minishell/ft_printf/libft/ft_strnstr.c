/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:15:09 by jnho              #+#    #+#             */
/*   Updated: 2023/02/20 12:38:15 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	idx;
	size_t	sub_idx;

	idx = 0;
	if (!substr[0])
		return ((char *)str);
	while (idx < len && str[idx])
	{
		sub_idx = 0;
		if (str[idx] == substr[sub_idx])
		{
			while (substr[sub_idx] && idx + sub_idx < len)
			{
				if (str[idx + sub_idx] != substr[sub_idx])
					break ;
				sub_idx++;
			}
			if (substr[sub_idx] == '\0')
				return ((char *)str + idx);
		}
		idx++;
	}
	return (0);
}
