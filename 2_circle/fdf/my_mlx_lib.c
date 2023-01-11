/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:01:08 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 17:35:46 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void    my_mlx_put_dot(t_image *mlx_image, int x, int y, int color)
{
    int     dot_idx;

    dot_idx = y * mlx_image->size_line + x * (mlx_image->bits_per_pixel / 8);
    if (dot_idx < 0 || dot_idx >= WIN_LEN * WIN_LEN * 4)
        return ;
    *(unsigned int *)(mlx_image->img_addr + dot_idx) = color;
}

void my_mlx_get_window_image(t_image *mlx_image)
{
    void    *mlx_ptr;
    void    *window_ptr;
    void    *image_ptr;
    char    *img_addr;

    mlx_ptr = mlx_init();
    window_ptr = mlx_new_window(mlx_ptr, WIN_LEN, WIN_LEN, "fdf");
    image_ptr = mlx_new_image(mlx_ptr, WIN_LEN, WIN_LEN);
    img_addr = mlx_get_data_addr(image_ptr, &mlx_image->bits_per_pixel, \
    &mlx_image->size_line, &mlx_image->endian);
    mlx_image->img_addr = img_addr;
    mlx_image->image_ptr = image_ptr;
    mlx_image->mlx_ptr = mlx_ptr;
    mlx_image->window_ptr = window_ptr;
}

void    my_mlx_put_image_to_window(t_image *mlx_image, int x, int y)
{
    mlx_put_image_to_window(mlx_image->mlx_ptr, mlx_image->window_ptr, \
    mlx_image->image_ptr, x, y);
}
