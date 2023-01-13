/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_key_hook_move_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:15:59 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 13:56:44 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdlib.h>

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
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->player[0], to);
	sl_map->player_idx = to;
}

void	sl_mlx_move_enemy(int from, int to, t_hook_vars *vars)
{
	t_map		*sl_map;
	t_window	*window;
	t_xpm_img	*xpm_imgs;

	sl_map = vars->sl_map;
	window = vars->window;
	xpm_imgs = vars->xpm_imgs;
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->floor, from);
	if (to == sl_map->player_idx)
		sl_key_hook_esc(window);
	sl_mlx_put_image_to_window(window, sl_map, xpm_imgs->enemy[0], to);
	sl_map->enemy_idx = to;
}

void	sl_key_hook_move_enemy(t_hook_vars *hook_vars)
{
	t_map	*sl_map;
	int		direction;
	int		m_idx;

	sl_map = hook_vars->sl_map;
	while (1)
	{
		direction = rand() % 4;
		if (direction == 0)
			m_idx = sl_map->enemy_idx - sl_map->width;
		else if (direction == 1)
			m_idx = sl_map->enemy_idx - 1;
		else if (direction == 2)
			m_idx = sl_map->enemy_idx + sl_map->width;
		else if (direction == 3)
			m_idx = sl_map->enemy_idx + 1;
		if (0 < m_idx && m_idx < sl_map->map_size && sl_map->map[m_idx] == '0')
			break ;
	}
	sl_mlx_move_enemy(sl_map->enemy_idx, m_idx, hook_vars);
}

void	sl_mlx_draw_string_move_cnt(t_hook_vars *vars, int m_cnt)
{
	t_map		*sl_map;
	t_xpm_img	*xpm_imgs;
	void		*mlx_ptr;
	void		*window_ptr;
	int			color;

	sl_map = vars->sl_map;
	mlx_ptr = vars->window->mlx_ptr;
	window_ptr = vars->window->window_ptr;
	xpm_imgs = vars->xpm_imgs;
	color = 0xffffff;
	sl_mlx_put_image_to_window(vars->window, sl_map, xpm_imgs->wall, 0);
	mlx_string_put(mlx_ptr, window_ptr, 10, 10, color, ft_itoa(m_cnt));
}

void	sl_key_hook_move_player(t_hook_vars *hook_vars, int move_idx)
{
	t_map	*sl_map;

	sl_map = hook_vars->sl_map;
	if (0 <= move_idx && move_idx < sl_map->map_size)
	{
		if (move_idx == sl_map->enemy_idx)
			sl_key_hook_esc(hook_vars->window);
		if (sl_map->map[move_idx] == 'E' && !sl_map->item_cnt)
			sl_key_hook_esc(hook_vars->window);
		else if (sl_map->map[move_idx] != '1')
		{
			sl_mlx_move_player(sl_map->player_idx, move_idx, hook_vars);
			hook_vars->move_cnt++;
			sl_mlx_draw_string_move_cnt(hook_vars, hook_vars->move_cnt);
			sl_key_hook_move_enemy(hook_vars);
		}
	}
}
