/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:38:36 by jnho              #+#    #+#             */
/*   Updated: 2023/01/11 14:23:07 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void    sl_mlx_new_window(t_window *window, t_map *sl_map)
{
    void    *mlx_ptr;
    void    *window_ptr;
    int     width;
    int     height;

    mlx_ptr = mlx_init();
    width = (int)sl_map->width;
    height = (int)sl_map->height;
    window_ptr = mlx_new_window(mlx_ptr, width * 64, height * 64, "so_long");
    window->mlx_ptr = mlx_ptr;
    window->window_ptr = window_ptr;
}

void    sl_mlx_draw_image_back_ground(t_image *image, t_map *sl_map)
{
    
}

void    sl_mlx(t_map *sl_map)
{
    t_window    window;
    t_image     image;

    sl_mlx_new_window(&window, sl_map);
    // mlx 초기  그려주고
    sl_mlx_draw_image(&image, sl_map); 
    // mlx loop
    mlx_loop(window.mlx_ptr);
    //mlx_key_hook(); 상 하 좌 우 esc추가하기.
}