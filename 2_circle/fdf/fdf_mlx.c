/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:55:31 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 17:40:44 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "fdf.h"



void    my_mlx_draw_map(t_image *mlx_image, t_map *fdf_map)
{
    t_dot   cur_dot;
    t_dot   right_dot;
    t_dot   under_dot;
    int     map_idx;

    map_idx = 0;
    while (map_idx < fdf_map->width * fdf_map->height)
    {
        cur_dot = fdf_map->map[map_idx];
        if (map_idx + 1 < fdf_map->width * fdf_map->height)
        {
            right_dot = fdf_map->map[map_idx + 1];
            bresenham_line(mlx_image, cur_dot, right_dot);
        }
        if (map_idx + fdf_map->width < fdf_map->width * fdf_map->height)
        {
            under_dot = fdf_map->map[map_idx + fdf_map->width];
            bresenham_line(mlx_image, cur_dot, under_dot);
        }
        map_idx++;
    }
    my_mlx_put_image_to_window(mlx_image, 0, 0);
}

void    fdf_transform_isometric(t_map *fdf_map)
{
    int map_idx;

    map_idx = 0;
    while (map_idx < fdf_map->width * fdf_map->height)
    {
        fdf_transform_z(&fdf_map->map[map_idx], -15 * PI / 180);
        //fdf_transform_x(&fdf_map->map[map_idx], (-60 * PI / 180));
        printf("idx = %d x = %d y = %d z = %d\n",map_idx, fdf_map->map[map_idx].x, fdf_map->map[map_idx].y, fdf_map->map[map_idx].z);
        map_idx++;
    }
}

void    fdf_mlx(t_map *fdf_map)
{
    t_image     mlx_image;

    my_mlx_get_window_image(&mlx_image);
    fdf_transform_isometric(fdf_map);
    my_mlx_draw_map(&mlx_image, fdf_map);
    mlx_loop(mlx_image.mlx_ptr);
}