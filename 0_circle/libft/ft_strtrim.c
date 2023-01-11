/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:15:37 by jnho              #+#    #+#             */
/*   Updated: 2022/11/21 15:39:18 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char ch, char const *set)
{
	int	set_idx;

	set_idx = 0;
	while (set[set_idx])
	{
		if (ch == set[set_idx])
			return (1);
		set_idx++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	s_idx;

	s_idx = 0;
	while (s1[s_idx])
	{
		if (!is_set(s1[s_idx], set))
			break ;
		s_idx++;
	}
	return (s_idx);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	e_idx;

	e_idx = ft_strlen(s1) - 1;
	if (ft_strlen(s1) < e_idx)
		return (0);
	while (e_idx && s1[e_idx])
	{
		if (!is_set(s1[e_idx], set))
			break ;
		e_idx--;
	}
	return (e_idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_idx;
	size_t	e_idx;
	size_t	rtn_idx;
	char	*rtn_arr;

	if (!ft_strlen(s1))
		return (ft_strdup(""));
	s_idx = find_start(s1, set);
	e_idx = find_end(s1, set);
	if (s_idx > e_idx || (s_idx == e_idx && !s1[0]))
	{
		rtn_arr = (char *)malloc(1);
		if (!rtn_arr)
			return (0);
		rtn_arr[0] = 0;
		return (rtn_arr);
	}
	rtn_arr = (char *)malloc(e_idx - s_idx + 2);
	if (!rtn_arr)
		return (0);
	rtn_idx = 0;
	while (s_idx <= e_idx)
		rtn_arr[rtn_idx++] = s1[s_idx++];
	rtn_arr[rtn_idx] = 0;
	return (rtn_arr);
}
