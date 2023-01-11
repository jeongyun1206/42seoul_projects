/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:04 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 17:34:57 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void    fdf_transform_x(t_dot *dot, double degree)
{
    int prev_y;

    prev_y = dot->y;
	dot->y = prev_y * cos(degree) + (dot->z) * sin(degree);
	dot->z = -prev_y * sin(degree) + (dot->z) * cos(degree);
}

void    fdf_transform_y(t_dot *dot, double degree)
{
    int	prev_x;

	prev_x = dot->x;
	dot->x = prev_x * cos(degree) + (dot->z) * sin(degree);
	dot->z = -prev_x * sin(degree) + (dot->z) * cos(degree);
}

void    fdf_transform_z(t_dot *dot, double degree)
{
    int	prev_x;
	int	prev_y;

	prev_x = dot->x;
	prev_y = dot->y;
	dot->x = (prev_x - 500) * cos(degree) - (prev_y - 500) * sin(degree) + 500;
	dot->y = (prev_x - 500) * sin(degree) + (prev_y - 500) * cos(degree) + 500;
}