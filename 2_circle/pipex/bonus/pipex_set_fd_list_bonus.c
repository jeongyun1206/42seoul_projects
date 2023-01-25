/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_fd_list_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayongja <sayongja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:36:32 by sayongja          #+#    #+#             */
/*   Updated: 2023/01/25 22:15:48 by sayongja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "pipex_bonus.h"
#include "get_next_line/get_next_line.h"
#include "../libft/libft.h"

void pipex_set_fd_list(t_fd_list *fd_list, char **argv, int argc)
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

int pipex_get_here_doc_fd(char **env)
{
    int     pipe_fd[2];
    char    *here_doc_file;
    char    *here_doc_buf;
    int     rtn_fd;
    pid_t   pid;

    pipe(pipe_fd);
    pid = fork();
    if (pid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        execve("/usr/bin/mktemp", ft_split("/usr/bin/mktemp", 0), env);
    }
    here_doc_buf = get_next_line(pipe_fd[0]);
    here_doc_file = ft_substr(here_doc_buf, 0, ft_strlen(here_doc_buf) - 1);
    printf("%s\n", here_doc_file);
    rtn_fd = open(here_doc_file, O_RDWR);
    free(here_doc_file);
    free(here_doc_buf);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid, 0, 0);
    return (rtn_fd);
}

void    pipex_write_tmp_file(int tmp_file_fd, char *limiter)
{
    char    *std_input;
    char    *std_input_cmp;

    while (1)
    {
        std_input = get_next_line(0);
        if (!std_input)
            continue;
        if (std_input[ft_strlen(std_input) - 1] == '\n')
            std_input_cmp = ft_substr(std_input, 0, ft_strlen(std_input) - 1);
        else
            ft_strlcpy(std_input_cmp, std_input, ft_strlen(std_input));
        if (!ft_strncmp(std_input_cmp, limiter, ft_strlen(limiter) + 1))
            break;
        write(tmp_file_fd, std_input, ft_strlen(std_input));
        free(std_input_cmp);
        free(std_input);
    }
    free(std_input);
}

void    pipex_set_fd_list_here_doc(t_fd_list *fd_list, char **av, int ac, char **env)
{
    int pipe_idx;

    fd_list->file1_fd = pipex_get_here_doc_fd(env);
    if (fd_list->file1_fd == -1)
        perror("");
    pipex_write_tmp_file(fd_list->file1_fd, av[2]);
    fd_list->file2_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_list->file2_fd == -1)
        exit(1);
    fd_list->pipe_list = (int **)malloc(sizeof(int *) * (ac - 5));
    if (!fd_list->pipe_list)
        exit(1);
    pipe_idx = 0;
    while (pipe_idx < ac - 5)
    {
        fd_list->pipe_list[pipe_idx] = (int *)malloc(sizeof(int) * 2);
        if (!fd_list->pipe_list[pipe_idx])
            exit(1);
        if (pipe(fd_list->pipe_list[pipe_idx]) == -1)
            exit(1);
        pipe_idx++;
    }
}
