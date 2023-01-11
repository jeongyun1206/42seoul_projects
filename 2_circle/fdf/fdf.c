/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:06:18 by jnho              #+#    #+#             */
/*   Updated: 2022/12/30 16:29:40 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

int main(int argc, char **argv)
{
    t_map   fdf_map;
    int     fd;
    
    if (argc != 2)
        exit(1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(1);
    fdf_get_map(&fdf_map, fd);
    close(fd);
    fdf_mlx(&fdf_map);
}