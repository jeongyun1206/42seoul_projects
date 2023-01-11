/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parcing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:12 by jnho              #+#    #+#             */
/*   Updated: 2023/01/11 13:32:42 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void    sl_map_parcing_get_map(t_map *sl_map, int fd)
{
    char    *map;
    
    sl_map->width = 0;
    sl_map->map = get_next_line(fd);
    while (sl_map->map[sl_map->width] != '\n' && sl_map->map[sl_map->width])
        sl_map->width++;
    sl_map->height = 1;
    map = get_next_line(fd);
    while (map)
    {
        sl_map->height++;
        sl_map->map = ft_strjoin(sl_map->map, map);
        map = get_next_line(fd);
    }
}

void    sl_map_parcing_confirm_map_size(t_map *sl_map)
{
    size_t  idx;
    size_t     confirm_width;

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
        {
            printf("map_size_error\n");
            exit(1);
        }
        if (sl_map->map[idx] == '\n')
            idx++;
    }
}

void    sl_map_parcing_count_map_elements(t_map *sl_map)
{
    size_t  idx;
    int     exit_cnt;
    int     player_cnt;

    idx = 0;
    exit_cnt = 0;
    player_cnt = 0;
    sl_map->item_cnt = 0;
    while (sl_map->map[idx])
    {
        if (sl_map->map[idx] == '0' || sl_map->map[idx] == '1' 
            || sl_map->map[idx] == '\n')
        {
            idx++;
            continue;
        }
        else if (sl_map->map[idx] == 'C')
            sl_map->item_cnt++;
        else if (sl_map->map[idx] == 'E' && !exit_cnt)
            exit_cnt++;
        else if (sl_map->map[idx] == 'P' && !player_cnt)
            player_cnt++;
        else
        {
            perror("error\n");
            exit(1);
        }
        idx++;
    }
}

void    sl_map_parcing_confirm_map_wall(t_map *sl_map)
{
    size_t idx;
    char    *m;
    size_t  w;
    size_t  h;

    idx = 0;
    m = sl_map->map;
    w = sl_map->width;
    h = sl_map->height;
    while (m[idx])
    {
        if (idx < w && m[idx] != '1')
        {
            perror("wall_error\n");
            exit(1); 
        }
        if (((h - 1) * (w + 1) <= idx && idx <= h * (w + 1) - 2) && m[idx] != '1')
        {
            perror("wall_error\n");
            exit(1); 
        }
        if ((idx % (w + 1) == 0 || idx % (w + 1) == w - 1) && m[idx] != '1')
        {
            perror("wall_error\n");
            exit(1);
        }
        idx++;
    }
}

t_map   sl_map_parcing(int fd)
{
    t_map sl_map;

    sl_map_parcing_get_map(&sl_map, fd);
    sl_map_parcing_confirm_map_size(&sl_map);
    sl_map_parcing_count_map_elements(&sl_map);
    sl_map_parcing_confirm_map_wall(&sl_map);
    sl_map_parcing_confirm_map_valid(&sl_map);
    return (sl_map);
}