/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:29:16 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 16:26:19 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#define WIN_LEN 1000
#define PI 3.1415926
typedef struct s_dot
{
    int x;
    int y;
    int z;
    int color;
}   t_dot;

typedef struct s_map
{
    int width;
    int height;
    int standard_dist;
    t_dot *map;
}   t_map;

typedef struct s_image
{
    void    *mlx_ptr;
    void    *window_ptr;
    void    *image_ptr;
    char    *img_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
} t_image;

void    fdf_get_map(t_map *fdf_map, int fd);
void    fdf_mlx(t_map *fdf_map);

void    my_mlx_put_dot(t_image *mlx_image, int x, int y, int color);
void    my_mlx_get_window_image(t_image *mlx_image);
void    my_mlx_put_image_to_window(t_image *mlx_image, int x, int y);

void    bresenham_line(t_image *mlx_image, t_dot cur_dot, t_dot next_dot);

void    fdf_transform_x(t_dot *dot, double degree);
void    fdf_transform_y(t_dot *dot, double degree);
void    fdf_transform_z(t_dot *dot, double degree);