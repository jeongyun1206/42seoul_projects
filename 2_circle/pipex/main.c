/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:31 by jnho              #+#    #+#             */
/*   Updated: 2023/01/17 16:22:01 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
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
// < file1 cmd1 | cmd2 > file2 
#include <stdio.h>
int main(int argc, char **argv, char **env)
{
    t_cmd_line cmd_line;

    if (argc != 5)
        return (0);
    pipex_set_cmd_line(&cmd_line, argv, argc, env);
    pipex_execute_cmd_line(&cmd_line);
}