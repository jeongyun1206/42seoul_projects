/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:23:27 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 21:14:25 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_cnt(char const *str, char c)
{
	size_t	str_idx;
	size_t	split_cnt;
	int		flag;

	split_cnt = 0;
	flag = 1;
	str_idx = 0;
	while (str[str_idx])
	{
		if (str[str_idx] == c)
			flag = 1;
		else if (str[str_idx] != c && flag)
		{
			flag = 0;
			split_cnt++;
		}
		str_idx++;
	}
	return (split_cnt);
}

static char	*ft_malloc_split_word(char const *str, size_t *str_idx, char c)
{
	size_t	str_len;
	size_t	rtn_arr_idx;
	char	*rtn_arr;

	while (str[*str_idx] == c)
		(*str_idx)++;
	str_len = 0;
	while (str[(*str_idx) + str_len] != c && str[(*str_idx) + str_len])
		str_len++;
	rtn_arr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!rtn_arr)
		return (0);
	rtn_arr_idx = 0;
	while (str[*str_idx] != c && str[*str_idx])
		rtn_arr[rtn_arr_idx++] = str[(*str_idx)++];
	rtn_arr[rtn_arr_idx] = '\0';
	return (rtn_arr);
}

static void	free_all(char **rtn_split, size_t split_idx)
{
	size_t	idx;

	idx = 0;
	while (idx < split_idx)
	{
		free(rtn_split[idx]);
		idx++;
	}
	free(rtn_split);
}

char	**ft_split(char const *str, char c)
{
	char	**rtn_split;
	size_t	split_cnt;
	size_t	split_idx;
	size_t	str_idx;

	if (!str)
		return (0);
	split_cnt = ft_split_cnt(str, c);
	rtn_split = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (!rtn_split)
		return (0);
	split_idx = 0;
	str_idx = 0;
	while (split_idx < split_cnt)
	{
		rtn_split[split_idx] = ft_malloc_split_word(str, &str_idx, c);
		if (!rtn_split[split_idx])
		{
			free_all(rtn_split, split_idx);
			return (0);
		}
		split_idx++;
	}
	rtn_split[split_idx] = 0;
	return (rtn_split);
}
