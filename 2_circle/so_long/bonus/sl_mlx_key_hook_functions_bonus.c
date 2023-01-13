/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_key_hook_functions_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:45:03 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 13:54:17 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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
