/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:38:36 by jnho              #+#    #+#             */
/*   Updated: 2023/01/12 15:20:30 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
#include "so_long.h"

void	sl_mlx_new_window(t_window *window, t_map *sl_map)
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		width;
	int		height;

	mlx_ptr = mlx_init();
	width = sl_map->width;
	height = sl_map->height;
	window_ptr = mlx_new_window(mlx_ptr, width * 64, height * 64, "so_long");
	window->mlx_ptr = mlx_ptr;
	window->window_ptr = window_ptr;
}

void	sl_mlx_get_elements_image_from_xpm(void *mlx, t_xpm_img *imgs)
{
	int	x;
	int	y;

	imgs->player = mlx_xpm_file_to_image(mlx, "./img/player_f0.xpm", &x, &y);
	imgs->floor = mlx_xpm_file_to_image(mlx, "./img/floor.xpm", &x, &y);
	imgs->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &x, &y);
	imgs->exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &x, &y);
	imgs->item = mlx_xpm_file_to_image(mlx, "./img/item.xpm", &x, &y);
}

int	sl_mlx_put_image_to_window(t_window *w, t_map *m, void *img, int i)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = w->mlx_ptr;
	win_ptr = w->window_ptr;
	x = (i % m->width) * 64;
	y = (i / m->width) * 64;
	return (mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y));
}

void	sl_mlx_draw_map(t_window *win, t_map *sl_map, t_xpm_img *xpm_imgs)
{
	int	idx;

	idx = 0;
	while (sl_map->map[idx])
	{
		sl_mlx_put_image_to_window(win, sl_map, xpm_imgs->floor, idx);
		if (sl_map->map[idx] == '1')
			sl_mlx_put_image_to_window(win, sl_map, xpm_imgs->wall, idx);
		else if (sl_map->map[idx] == 'P')
		{
			sl_mlx_put_image_to_window(win, sl_map, xpm_imgs->player, idx);
			sl_map->map[idx] = '0';
			sl_map->player_idx = idx;
		}
		else if (sl_map->map[idx] == 'E')
			sl_mlx_put_image_to_window(win, sl_map, xpm_imgs->exit, idx);
		else if (sl_map->map[idx] == 'C')
			sl_mlx_put_image_to_window(win, sl_map, xpm_imgs->item, idx);
		idx++;
	}
}

void	sl_mlx(t_map *sl_map)
{
	t_window	window;
	t_xpm_img	xpm_imgs;
	t_hook_vars	hook_vars;

	sl_mlx_new_window(&window, sl_map);
	sl_mlx_get_elements_image_from_xpm(window.mlx_ptr, &xpm_imgs);
	sl_mlx_draw_map(&window, sl_map, &xpm_imgs);
	hook_vars = sl_set_hook_vars(sl_map, &window, &xpm_imgs);
	mlx_key_hook(window.window_ptr, sl_key_hook, &hook_vars);
	mlx_loop(window.mlx_ptr);
}
