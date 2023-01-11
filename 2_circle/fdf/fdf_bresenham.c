/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:29:10 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 17:39:39 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void    bresenham_line(t_image *mlx_image, t_dot cur_dot, t_dot next_dot)
{
    int w;
    int h;
    int m;

    w = next_dot.x - cur_dot.x;
    h = next_dot.y - cur_dot.y;
    if (w > h)
    {
        m = w - 2 * h;
        while (cur_dot.x <= next_dot.x)
        {
            my_mlx_put_dot(mlx_image, cur_dot.x, cur_dot.y, cur_dot.color);
            m -= 2 * h;
            cur_dot.x++;
            if (m < 0)
            {
                cur_dot.y++;
                m += 2 * w;
            }
        }
    }
    else
    {
        m = 2 * w - h;
        while (cur_dot.y <= next_dot.y)
        {
            my_mlx_put_dot(mlx_image, cur_dot.x, cur_dot.y, cur_dot.color);
            m += 2 * w;
            cur_dot.y++;
            if (m > 0)
            {
                cur_dot.x++;
                m -= 2 * h;
            }
        }
    }
}