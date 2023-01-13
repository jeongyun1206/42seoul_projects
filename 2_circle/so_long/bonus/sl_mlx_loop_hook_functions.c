/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_loop_hook_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:58:35 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 13:57:31 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_loop_hook_sprite_player(t_hook_vars *vars, int state)
{
	t_map		*sl_map;
	t_window	*window;
	t_xpm_img	*xpm_imgs;
	int			p_idx;

	sl_map = vars->sl_map;
	window = vars->window;
	xpm_imgs = vars->xpm_imgs;
	p_idx = sl_map->player_idx;
	if (sl_map->map[p_idx] == 'E')
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->exit, p_idx);
	else
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->floor, p_idx);
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->player[state], p_idx);
}

void	sl_loop_hook_sprite_enemy(t_hook_vars *vars, int state)
{
	t_map		*sl_map;
	t_window	*window;
	t_xpm_img	*xpm_imgs;
	int			e_idx;

	sl_map = vars->sl_map;
	window = vars->window;
	xpm_imgs = vars->xpm_imgs;
	e_idx = sl_map->enemy_idx;
	if (sl_map->map[e_idx] == 'E')
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->exit, e_idx);
	else
		sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->floor, e_idx);
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->enemy[state], e_idx);
}

int	sl_loop_hook(t_hook_vars *hook_vars)
{
	static int	called_cnt;
	static int	state;

	called_cnt++;
	if (called_cnt == 2500)
	{
		called_cnt = 0;
		state++;
		if (state == 4)
			state = 0;
		sl_loop_hook_sprite_player(hook_vars, state);
		sl_loop_hook_sprite_enemy(hook_vars, state);
	}
	return (1);
}
