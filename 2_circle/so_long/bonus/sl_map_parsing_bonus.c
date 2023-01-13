/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:12 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 13:49:55 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	sl_map_parsing_get_map(t_map *sl_map, int fd)
{
	char	*map;
	char	*buff;

	sl_map->width = 0;
	sl_map->map = get_next_line(fd);
	while (sl_map->map[sl_map->width] != '\n' && sl_map->map[sl_map->width])
		sl_map->width++;
	sl_map->height = 1;
	map = get_next_line(fd);
	while (map)
	{
		sl_map->height++;
		buff = ft_strjoin(sl_map->map, map);
		free(sl_map->map);
		free(map);
		sl_map->map = buff;
		map = get_next_line(fd);
	}
}

void	sl_map_parsing_confirm_map_size(t_map *sl_map)
{
	int	idx;
	int	confirm_width;

	idx = 0;
	while (sl_map->map[idx])
	{
		confirm_width = 0;
		while (sl_map->map[idx] && sl_map->map[idx] != '\n')
		{
			confirm_width++;
			idx++;
		}
		if (confirm_width != sl_map->width)
			error("map_size_error\n");
		if (sl_map->map[idx] == '\n')
			idx++;
	}
}

void	sl_map_parsing_count_map_elements(t_map *sl_map)
{
	int	idx;
	int	cnt[3];

	idx = -1;
	ft_memset(cnt, 0, sizeof(int) * 3);
	sl_map->item_cnt = 0;
	while (sl_map->map[++idx])
	{
		if (sl_map->map[idx] == '0' || sl_map->map[idx] == '1'
			|| sl_map->map[idx] == '\n')
			continue ;
		else if (sl_map->map[idx] == 'C')
			sl_map->item_cnt++;
		else if (sl_map->map[idx] == 'E')
			cnt[0]++;
		else if (sl_map->map[idx] == 'P')
			cnt[1]++;
		else if (sl_map->map[idx] == 'B')
			cnt[2]++;
		else
			error("map_elements_error\n");
	}
	if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1)
		error("map_elements_error\n");
}

void	sl_map_parsing_confirm_map_wall(t_map *sl_map)
{
	int		idx;
	char	*m;
	int		w;
	int		h;

	idx = 0;
	m = sl_map->map;
	w = sl_map->width;
	h = sl_map->height;
	while (m[idx])
	{
		if (m[idx] != '1')
		{
			if (idx < w)
				error("wall_error\n");
			if ((h - 1) * (w + 1) <= idx && idx <= h * (w + 1) - 2)
				error("wall_error\n");
			if (idx % (w + 1) == 0 || idx % (w + 1) == w - 1)
				error("wall_error\n");
		}
		idx++;
	}
}

t_map	sl_map_parsing(int fd)
{
	t_map	sl_map;

	sl_map_parsing_get_map(&sl_map, fd);
	sl_map_parsing_confirm_map_size(&sl_map);
	sl_map_parsing_count_map_elements(&sl_map);
	sl_map_parsing_confirm_map_wall(&sl_map);
	sl_map_parsing_confirm_map_valid(&sl_map);
	sl_map_parsing_copy_map_without_nl(&sl_map);
	return (sl_map);
}
