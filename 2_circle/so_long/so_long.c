/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:10 by jnho              #+#    #+#             */
/*   Updated: 2023/01/11 13:38:17 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int     fd;
    t_map   sl_map;

    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0);
    sl_map = sl_map_parcing(fd);
    sl_mlx(&sl_map);
}