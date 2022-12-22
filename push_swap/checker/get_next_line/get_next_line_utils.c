/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:43:07 by jnho              #+#    #+#             */
/*   Updated: 2022/12/15 17:01:14 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn_arr;
	size_t	idx;
	size_t	s_len;

	s_len = gnl_strlen(s);
	if (s_len - start <= 0)
		return (0);
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

size_t	gnl_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}
