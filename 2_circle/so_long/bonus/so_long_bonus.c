/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:10 by jnho              #+#    #+#             */
/*   Updated: 2023/01/15 14:12:18 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <fcntl.h>

int	exit_hook(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->window_ptr);
	exit(0);
}

void	error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	exit(1);
}

void	confirm_file_name(char *file_name)
{
	int	idx;

	idx = 0;
	file_name = ft_strchr(file_name, '.');
	if (!file_name)
		error("wrong file name\n");
	if (ft_strncmp(file_name, ".ber", ft_strlen(file_name) + 4) != 0)
		error("wrong file name\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	sl_map;

	if (argc != 2)
		return (0);
	confirm_file_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	sl_map = sl_map_parsing(fd);
	sl_mlx(&sl_map);
	exit(0);
}
