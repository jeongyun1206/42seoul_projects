/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:37:22 by jnho              #+#    #+#             */
/*   Updated: 2023/02/07 14:03:24 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	idx;
	char	*rtn_str;

	s_len = ft_strlen(s);
	rtn_str = (char *)malloc(s_len + 1);
	if (!rtn_str)
		exit(1);
	idx = 0;
	while (s[idx])
	{
		rtn_str[idx] = f(idx, s[idx]);
		idx++;
	}
	rtn_str[idx] = '\0';
	return (rtn_str);
}
