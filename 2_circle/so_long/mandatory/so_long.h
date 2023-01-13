/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:07 by jnho              #+#    #+#             */
/*   Updated: 2023/01/13 13:04:13 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_map
{
	char	*map;
	int		width;
	int		height;
	int		item_cnt;
	int		player_idx;
	int		map_size;
}	t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*window_ptr;
}	t_window;

typedef struct s_xpm_img
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*item;
}	t_xpm_img;

typedef struct s_hook_vars
{
	t_map		*sl_map;
	t_window	*window;
	t_xpm_img	*xpm_imgs;
	int			move_cnt;
	int			hook_control;
}	t_hook_vars;

void		error(char *error_message);

void		sl_map_parsing_get_map(t_map *sl_map, int fd);
void		sl_map_parsing_confirm_map_size(t_map *sl_map);
void		sl_map_parsing_count_map_elements(t_map *sl_map);
void		sl_map_parsing_confirm_map_wall(t_map *sl_map);
t_map		sl_map_parsing(int fd);

int			dfs(t_map *sl_map, char *tmp_map, int idx, char to_find);
int			sl_map_parsing_find_player_location(char *map);
void		sl_map_parsing_confirm_map_valid(t_map *sl_map);
void		sl_map_parsing_copy_map_without_nl(t_map *sl_map);

void		sl_mlx(t_map *sl_map);
void		sl_mlx_new_window(t_window *window, t_map *sl_map);
void		sl_mlx_get_elements_image_from_xpm(void *mlx, t_xpm_img *imgs);
int			sl_mlx_put_image_to_window(t_window *w, t_map *m, void *img, int i);
void		sl_mlx_draw_map(t_window *win, t_map *sl_map, t_xpm_img *xmp_imgs);

t_hook_vars	sl_set_hook_vars(t_map *m, t_window *w, t_xpm_img *imgs);
void		sl_key_hook_esc(t_window *window);
void		sl_mlx_move_player(int from, int to, t_hook_vars *vars);
void		sl_key_hook_move_player(t_hook_vars *hook_vars, int move_idx);
int			sl_key_hook(int key_code, t_hook_vars *hook_vars);

#endif
