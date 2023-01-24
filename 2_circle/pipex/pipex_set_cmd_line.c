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
#include "./libft/libft.h"
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

char ***pipex_get_cmd_list(char **argv, int cmd_len)
{
    char    ***cmd_list;
    int     cmd_list_idx;
    int     argv_idx;

    cmd_list = (char ***)malloc(sizeof(char **) * (cmd_len + 1));
    if (!cmd_list)
        exit(errno);
    cmd_list_idx = 0;
    argv_idx = 2;
    while (cmd_list_idx < cmd_len)
    {
        cmd_list[cmd_list_idx] = ft_split(argv[argv_idx], ' ');
        if (!cmd_list[cmd_list_idx])
            exit(errno);
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
    path_list = 0;
    while (env[++env_idx])
    {
        if (ft_strncmp("PATH=", env[env_idx], 5) == 0)
        {
            path_list = ft_split(env[env_idx] + 5, ':');
            if (!path_list)
                exit(errno);
            break ;
        }
    }
    path_idx = -1;
    while (path_list[++path_idx])
    {
        buff = ft_strjoin(path_list[path_idx], "/");
        if (!buff)
            exit(errno);
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
            exit(errno);
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

void    pipex_set_cmd_list(t_cmd_list *cmd_list, char **argv, int argc, char **env)
{
    char    *cmd_path;
    int     cmd_idx;

    cmd_list->cmd_len = argc - 3;
    cmd_list->cmd_list = pipex_get_cmd_list(argv, cmd_list->cmd_len);
    cmd_list->env = env;
    cmd_idx = 0;
    while (cmd_list->cmd_list[cmd_idx])
    {
        cmd_path = pipex_get_cmd_path(cmd_list->cmd_list[cmd_idx][0], env);
        if (cmd_path)
        {
            free(cmd_list->cmd_list[cmd_idx][0]);
            cmd_list->cmd_list[cmd_idx][0] = cmd_path;
        }
        cmd_idx++;
    }
}

void    pipex_set_fd_list(t_fd_list *fd_list, char **argv, int argc)
{
    int pipe_idx;

    fd_list->file1_fd = open(argv[1], O_RDONLY);
    if (fd_list->file1_fd == -1)
        perror("");
    fd_list->file2_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_list->file2_fd == -1)
        exit(1);
    fd_list->pipe_list = (int **)malloc(sizeof(int *) * (argc - 4));
    if (!fd_list->pipe_list)
        exit(1);
    pipe_idx = 0;
    while (pipe_idx < argc - 4)
    {
        fd_list->pipe_list[pipe_idx] = (int *)malloc(sizeof(int) * 2);
        if (!fd_list->pipe_list[pipe_idx])
            exit(1);
        if (pipe(fd_list->pipe_list[pipe_idx]) == -1)
            exit(1);
        pipe_idx++;
    }
}