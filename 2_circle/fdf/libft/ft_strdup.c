/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:46:53 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 19:52:03 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	idx;
	size_t	str_len;
	char	*rtn_arr;

	str_len = 0;
	while (str[str_len])
		str_len++;
	rtn_arr = (char *)malloc(str_len + 1);
	if (!rtn_arr)
		return (0);
	idx = 0;
	while (str[idx])
	{
		rtn_arr[idx] = str[idx];
		idx++;
	}
	rtn_arr[idx] = '\0';
	return (rtn_arr);
}
