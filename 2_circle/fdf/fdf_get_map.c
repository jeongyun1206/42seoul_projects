/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:33:44 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 17:32:45 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int fdf_atoi_hex(char *hex_string)
{
    int rtn_num;
    int idx;

    idx = 3;
    rtn_num = 0;
    while (idx < 9)
    {
        rtn_num *= 16;
        if (ft_isdigit(hex_string[idx]))
            rtn_num += hex_string[idx] - '0';
        else
            rtn_num += hex_string[idx] - 'A' + 10;
        idx++;
    }
    return (rtn_num);
}

void    fdf_get_map_dot_info(char *map_src, t_map *fdf_map)
{
    size_t  src_idx;
    size_t  map_idx;

    src_idx = 0;
    map_idx = 0;
    while (map_src[src_idx])
    {
        if (ft_isdigit(map_src[src_idx]))
            fdf_map->map[map_idx].z = ft_atoi(map_src + src_idx);
        while (ft_isdigit(map_src[src_idx]))
            src_idx++;
        if (map_src[src_idx] == ',')
        {
            fdf_map->map[map_idx].color = fdf_atoi_hex(map_src + src_idx);
            src_idx += 9;
        }
        else
            fdf_map->map[map_idx].color = 0x00FFFFFF;
        while (map_src[src_idx] == ' ' || map_src[src_idx] == '\n')
            src_idx++;
        fdf_map->map[map_idx].x = map_idx % fdf_map->width;
        fdf_map->map[map_idx].y = map_idx / fdf_map->width;
        map_idx++;
    }
}

void    fdf_get_map_info(char *map_src, t_map *fdf_map)
{
    size_t  src_idx;

    fdf_map->height = 0;
    src_idx = 0;
    while (map_src[src_idx])
    {
        if (map_src[src_idx] == '\n')
            fdf_map->height++;
        src_idx++;
    }
    fdf_map->width = 0;
    src_idx = 0;
    while (map_src[src_idx] != '\n')
    {
        if (map_src[src_idx] != ' ')
            fdf_map->width++;
        while (map_src[src_idx] != ' ' && map_src[src_idx] != '\n')
            src_idx++;
        if (map_src[src_idx] == '\n')
            break;
        src_idx++;
    }
}

char    *fdf_get_map_src(int fd)
{
    char    *map_src;
    char    *add_src;

    map_src = get_next_line(fd);
    add_src = get_next_line(fd);
    while (add_src)
    {
        map_src = ft_strjoin(map_src, add_src);
        add_src = get_next_line(fd);
    }
    return (map_src);
}

void    fdf_get_map(t_map *fdf_map, int fd)
{
    char    *map_src;
    int     dot_cnt;
    int     dot_idx;

    map_src = fdf_get_map_src(fd);
    fdf_get_map_info(map_src, fdf_map);
    dot_cnt = fdf_map->width * fdf_map->height;
    fdf_map->map = (t_dot *)malloc(sizeof(t_dot) * dot_cnt);
    if (!fdf_map->map)
        exit(1);
    fdf_get_map_dot_info(map_src, fdf_map);
    if (fdf_map->width > fdf_map->height)
        fdf_map->standard_dist = 750 / fdf_map->width;
    else
        fdf_map->standard_dist = 750 / fdf_map->height;
    dot_idx = 0;
    while (dot_idx < dot_cnt)
    {
        fdf_map->map[dot_idx].x *= fdf_map->standard_dist;
        fdf_map->map[dot_idx].y *= fdf_map->standard_dist;
        fdf_map->map[dot_idx].z *= fdf_map->standard_dist / 10;
        dot_idx++;
    }
}