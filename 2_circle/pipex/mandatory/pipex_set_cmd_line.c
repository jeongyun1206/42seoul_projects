/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_cmd_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:34 by jnho              #+#    #+#             */
/*   Updated: 2023/01/24 15:27:46 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

void    pipex_get_cmd_list(char **argv, char ***cmd_list)
{
    cmd_list[0] = ft_split(argv[2], ' ');
    if (!cmd_list[0])
        exit(1);
    cmd_list[1] = ft_split(argv[3], ' ');
    if (!cmd_list[1])
        exit(1);
}

char **pipex_get_path_list(char **env)
{
    char    **path_list;
    char    *buff;
    int     path_idx;
    int     env_idx;

    env_idx = -1;
    path_list = 0;
    while (env[++env_idx])
    {
        if (ft_strncmp("PATH=", env[env_idx], 5) == 0)
        {
            path_list = ft_split(env[env_idx] + 5, ':');
            if (!path_list)
                exit(1);
            break ;
        }
    }
    path_idx = -1;
    while (path_list[++path_idx])
    {
        buff = ft_strjoin(path_list[path_idx], "/");
        if (!buff)
            exit(1);
        free(path_list[path_idx]);
        path_list[path_idx] = buff;
    }
    return (path_list);
}

char    *pipex_get_cmd_path(char *cmd, char **env)
{
    char    **path_list;
    char    *cmd_path;
    int     path_idx;

    path_list = pipex_get_path_list(env);
    path_idx = 0;
    while (path_list[path_idx])
    {
        cmd_path = ft_strjoin(path_list[path_idx], cmd);
        if (!cmd_path)
            exit(1);
        if (access(cmd_path, 1) == 0)
        {
            free_2d_array(path_list);
            return (cmd_path);
        }
        free(cmd_path);
        path_idx++;
    }
    free_2d_array(path_list);
    return (0);
}

void    pipex_set_cmd_list(t_cmd_list *cmd_list, char **argv, char **env)
{
    char    *cmd_path;

    cmd_list->env = env;
    pipex_get_cmd_list(argv, cmd_list->cmd_list);
    cmd_path = pipex_get_cmd_path(cmd_list->cmd_list[0][0], env);
    if (cmd_path)
    {
        free(cmd_list->cmd_list[0][0]);
        cmd_list->cmd_list[0][0] = cmd_path;
    }
    cmd_path = pipex_get_cmd_path(cmd_list->cmd_list[1][0], env);
    if (cmd_path)
    {
        free(cmd_list->cmd_list[1][0]);
        cmd_list->cmd_list[1][0] = cmd_path;
    }
}

