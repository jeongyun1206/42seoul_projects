/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:31 by jnho              #+#    #+#             */
/*   Updated: 2023/01/19 14:49:03 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "pipex.h"
#include "./libft/libft.h"

void    free_2d_array(char **array)
{
    int idx;

    idx = 0;
    while (array[idx])
    {
        free(array[idx]);
        idx++;
    }
    free(array);
}

int main(int argc, char **argv, char **env)
{
    t_cmd_line cmd_line;

    //if (argc != 5)
    //    exit(errno);
    pipex_set_cmd_line(&cmd_line, argv, argc, env);
    pipex_execute_cmd_line(&cmd_line);
}