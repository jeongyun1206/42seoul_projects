/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:07 by jnho              #+#    #+#             */
/*   Updated: 2023/01/11 14:11:41 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    char    *map;
    size_t     width;
    size_t     height;
    int     item_cnt;
}   t_map;

typedef struct s_window
{
    void    *mlx_ptr;
    void    *window_ptr;
}   t_window;

typedef struct s_image
{
    void    *image;
    int     player_idx;
}   t_image;

void    sl_map_parcing_get_map(t_map *sl_map, int fd);
void    sl_map_parcing_confirm_map_size(t_map *sl_map);
void    sl_map_parcing_count_map_elements(t_map *sl_map);
void    sl_map_parcing_confirm_map_wall(t_map *sl_map);
t_map   sl_map_parcing(int fd);

int dfs(t_map *sl_map, char *tmp_map, size_t idx, char to_find);
size_t  sl_map_parcing_find_player_location(char *map);
void    sl_map_parcing_confirm_map_valid(t_map *sl_map);

void    sl_mlx(t_map *sl_map)