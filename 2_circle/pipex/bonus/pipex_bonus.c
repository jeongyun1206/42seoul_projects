/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayongja <sayongja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:31 by jnho              #+#    #+#             */
/*   Updated: 2023/01/25 22:09:33 by sayongja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "pipex_bonus.h"
#include "../libft/libft.h"

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

int main(int ac, char **av, char **env)
{
    t_cmd_list  cmd_list;
    t_fd_list   fd_list;

    if (!ft_strncmp(av[1], "here_doc", 9))
    {
        pipex_set_cmd_list(&cmd_list, av + 1, ac - 1, env);
        pipex_set_fd_list_here_doc(&fd_list, av, ac, env);
    }
    else
    {
        pipex_set_cmd_list(&cmd_list, av, ac, env);
        pipex_set_fd_list(&fd_list, av, ac);
    }
    pipex_execute_cmd_list(&cmd_list, &fd_list);
    exit(0);
}