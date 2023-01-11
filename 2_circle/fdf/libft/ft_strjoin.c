/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:16 by jnho              #+#    #+#             */
/*   Updated: 2022/11/18 17:24:37 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		rtn_len;
	size_t		rtn_idx;
	size_t		s_idx;
	char		*rtn_arr;

	if (!s1 || !s2)
		return (0);
	rtn_len = ft_strlen(s1) + ft_strlen(s2);
	rtn_arr = (char *)malloc(rtn_len + 1);
	if (!rtn_arr)
		return (0);
	rtn_idx = 0;
	s_idx = 0;
	while (s1[s_idx])
		rtn_arr[rtn_idx++] = s1[s_idx++];
	s_idx = 0;
	while (s2[s_idx])
		rtn_arr[rtn_idx++] = s2[s_idx++];
	rtn_arr[rtn_idx] = '\0';
	return (rtn_arr);
}
