/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:52:33 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:41:00 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	idx;

	idx = 0;
	if (!num)
		return (0);
	while (idx < num - 1)
	{
		if (!str1[idx] && !str2[idx])
			break ;
		if (str1[idx] != str2[idx])
			break ;
		idx++;
	}
	return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
}
