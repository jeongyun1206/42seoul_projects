/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing_cofrim_map_valid_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:51:52 by jnho              #+#    #+#             */
/*   Updated: 2023/01/15 12:08:47 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>
#include "../libft/libft.h"

int	dfs(t_map *sl_map, char *tmp_map, int idx, char to_find)
{
	int	rtn;

	if (sl_map->height * (sl_map->width + 1) - 2 < idx || idx < 0)
		return (0);
	if (tmp_map[idx] == '1')
		return (0);
	rtn = 0;
	if (tmp_map[idx] == to_find)
		rtn++;
	tmp_map[idx] = '1';
	rtn += dfs(sl_map, tmp_map, idx + sl_map->width + 1, to_find);
	rtn += dfs(sl_map, tmp_map, idx - (sl_map->width + 1), to_find);
	rtn += dfs(sl_map, tmp_map, idx - 1, to_find);
	rtn += dfs(sl_map, tmp_map, idx + 1, to_find);
	return (rtn);
}

int	sl_map_parsing_find_player_location(char *map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (map[idx] == 'P')
			break ;
		idx++;
	}
	return (idx);
}

void	sl_map_parsing_confirm_map_valid(t_map *sl_map)
{
	int		idx;
	char	*tmp_map;

	idx = sl_map_parsing_find_player_location(sl_map->map);
	tmp_map = ft_strdup(sl_map->map);
	if (sl_map->item_cnt != dfs(sl_map, tmp_map, idx, 'C'))
		error("invalid_map_error1\n");
	free(tmp_map);
	tmp_map = ft_strdup(sl_map->map);
	if (!dfs(sl_map, tmp_map, idx, 'E'))
		error("invalid_map_error2\n");
	free(tmp_map);
}

void	sl_map_parsing_copy_map_without_nl(t_map *sl_map)
{
	int		m_idx;
	int		cpy_idx;
	char	*cpy_map;

	m_idx = 0;
	cpy_idx = 0;
	cpy_map = (char *)malloc(sizeof(char) * sl_map->width * sl_map->height + 1);
	while (sl_map->map[m_idx])
	{
		if (sl_map->map[m_idx] != '\n')
		{
			cpy_map[cpy_idx] = sl_map->map[m_idx];
			cpy_idx++;
		}
		m_idx++;
	}
	cpy_map[sl_map->width * sl_map->height] = 0;
	free(sl_map->map);
	sl_map->map = cpy_map;
	sl_map->map_size = sl_map->width * sl_map->height;
}
