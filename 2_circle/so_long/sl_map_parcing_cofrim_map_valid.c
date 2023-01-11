/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parcing_cofrim_map_valid.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:51:52 by jnho              #+#    #+#             */
/*   Updated: 2023/01/11 13:17:03 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "so_long.h"

int dfs(t_map *sl_map, char *tmp_map, size_t idx, char to_find)
{
    int rtn;

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

size_t sl_map_parcing_find_player_location(char *map)
{
    size_t  idx;

    idx = 0;
    while (map[idx])
    {
        if (map[idx] == 'P')
            break;
        idx++;
    }
    return (idx);
}

void    sl_map_parcing_confirm_map_valid(t_map *sl_map)
{
    size_t idx;
    char    *tmp_map;

    idx = sl_map_parcing_find_player_location(sl_map->map);
    tmp_map = ft_strdup(sl_map->map);
    if (sl_map->item_cnt != dfs(sl_map, tmp_map, idx, 'C'))
    {
        perror("map_invalid_error\n");
        exit(1);
    }
    free(tmp_map);
    tmp_map = ft_strdup(sl_map->map);
    if (!dfs(sl_map, tmp_map, idx, 'E'))
    {
        perror("map_invalid_error\n");
        exit(1);
    }
    free(tmp_map);
}