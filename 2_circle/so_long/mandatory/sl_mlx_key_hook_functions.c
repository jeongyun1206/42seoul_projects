/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_key_hook_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:45:03 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 12:17:34 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../ft_printf/ft_printf.h"
#include <mlx.h>
#include <stdlib.h>

t_hook_vars	sl_set_hook_vars(t_map *m, t_window *w, t_xpm_img *imgs)
{
	t_hook_vars	hook_vars;

	hook_vars.move_cnt = 0;
	hook_vars.sl_map = m;
	hook_vars.window = w;
	hook_vars.xpm_imgs = imgs;
	return (hook_vars);
}

void	sl_key_hook_esc(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->window_ptr);
	exit(0);
}

void	sl_mlx_move_player(int from, int to, t_hook_vars *vars)
{
	t_map		*sl_map;
	t_window	*window;
	t_xpm_img	*xpm_imgs;

	sl_map = vars->sl_map;
	window = vars->window;
	xpm_imgs = vars->xpm_imgs;
	if (sl_map->map[from] == '0')
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->floor, from);
	else if (sl_map->map[from] == 'E')
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->exit, from);
	if (sl_map->map[to] == 'C')
	{
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->floor, to);
		sl_map->map[to] = '0';
		sl_map->item_cnt--;
	}
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->player, to);
	sl_map->player_idx = to;
}

void	sl_key_hook_move_player(t_hook_vars *hook_vars, int move_idx)
{
	t_map	*sl_map;

	sl_map = hook_vars->sl_map;
	if (0 <= move_idx && move_idx < sl_map->map_size)
	{
		if (sl_map->map[move_idx] == 'E' && !sl_map->item_cnt)
			sl_key_hook_esc(hook_vars->window);
		else if (sl_map->map[move_idx] != '1')
		{
			sl_mlx_move_player(sl_map->player_idx, move_idx, hook_vars);
			hook_vars->move_cnt++;
			ft_printf("move count = %d\n", hook_vars->move_cnt);
		}
	}
}

int	sl_key_hook(int key_code, t_hook_vars *hook_vars)
{
	t_map	*sl_map;

	sl_map = hook_vars->sl_map;
	if (key_code == KEY_ESC)
		sl_key_hook_esc(hook_vars->window);
	else if (key_code == KEY_W)
		sl_key_hook_move_player(hook_vars, sl_map->player_idx - sl_map->width);
	else if (key_code == KEY_A)
		sl_key_hook_move_player(hook_vars, sl_map->player_idx - 1);
	else if (key_code == KEY_S)
		sl_key_hook_move_player(hook_vars, sl_map->player_idx + sl_map->width);
	else if (key_code == KEY_D)
		sl_key_hook_move_player(hook_vars, sl_map->player_idx + 1);
	return (1);
}
