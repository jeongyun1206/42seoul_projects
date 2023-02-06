/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:18:47 by jnho              #+#    #+#             */
/*   Updated: 2023/02/03 17:31:32 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn_arr;
	size_t	idx;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		rtn_arr = (char *)malloc(1);
	else if (s_len - start + 1 <= len)
		rtn_arr = (char *)malloc(s_len - start + 1);
	else
		rtn_arr = (char *)malloc(len + 1);
	if (!rtn_arr)
		return (0);
	idx = 0;
	while (start < s_len && idx < len && s[start + idx])
	{
		rtn_arr[idx] = s[start + idx];
		idx ++;
	}
	rtn_arr[idx] = '\0';
	return (rtn_arr);
}
