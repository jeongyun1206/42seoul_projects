/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_cmd_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:27:34 by jnho              #+#    #+#             */
/*   Updated: 2023/01/17 16:26:44 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <fcntl.h>

char ***pipex_get_cmd_list(char **argv, int argc)
{
    char    ***cmd_list;
    int     cmd_list_idx;
    int     argv_idx;

    cmd_list = (char ***)malloc(sizeof(char **) * (argc - 2));
    if (!cmd_list)
        exit(1);
    cmd_list_idx = 0;
    argv_idx = 2;
    while (cmd_list_idx < argc - 3)
    {
        cmd_list[cmd_list_idx] = ft_split(argv[argv_idx], ' ');
        if (!cmd_list[cmd_list_idx])
            exit(1);
        cmd_list_idx++;
        argv_idx++;
    }
    cmd_list[cmd_list_idx] = 0;
    return (cmd_list);
}

char **pipex_get_path_list(char **env)
{
    char **path_list;
    char    *buff;
    int     path_idx;
    int     env_idx;

    env_idx = -1;
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

void    pipex_set_cmd_line(t_cmd_line *cmd_line, char **argv, int argc, char **env)
{
    char    *cmd_path;
    int     cmd_idx;

    cmd_line->file1_fd = open(argv[1], O_RDWR);
    cmd_line->file2_fd = open(argv[4], O_RDWR);
    cmd_line->cmd_list = pipex_get_cmd_list(argv, argc);
    cmd_line->env = env;
    pipe(cmd_line->pipe_fd);
    cmd_idx = 0;
    while (cmd_line->cmd_list[cmd_idx])
    {
        cmd_path = pipex_get_cmd_path(cmd_line->cmd_list[cmd_idx][0], env);
        if (cmd_path)
        {
            free(cmd_line->cmd_list[cmd_idx][0]);
            cmd_line->cmd_list[cmd_idx][0] = cmd_path;
        }
        cmd_idx++;
    }
}