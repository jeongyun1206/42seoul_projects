/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_fd_list_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:36:32 by sayongja          #+#    #+#             */
/*   Updated: 2023/01/27 15:51:21 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "pipex_bonus.h"
#include "get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	pipex_set_fd_list(t_fd_list *fd_list, char **av, int ac)
{
	int	pipe_idx;

	fd_list->file1_fd = open(av[1], O_RDONLY);
	if (fd_list->file1_fd == -1)
		perror("");
	fd_list->file2_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_list->file2_fd == -1)
		exit(1);
	fd_list->pipe_list = (int **)malloc(sizeof(int *) * (ac - 4));
	if (!fd_list->pipe_list)
		exit(1);
	pipe_idx = 0;
	while (pipe_idx < ac - 4)
	{
		fd_list->pipe_list[pipe_idx] = (int *)malloc(sizeof(int) * 2);
		if (!fd_list->pipe_list[pipe_idx])
			exit(1);
		if (pipe(fd_list->pipe_list[pipe_idx]) == -1)
			exit(1);
		pipe_idx++;
	}
}

char	*pipex_get_here_doc_file_name(char **env)
{
	int		pipe_fd[2];
	char	*file_name;
	char	*file_name_buf;
	pid_t	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execve("/usr/bin/mktemp", ft_split("/usr/bin/mktemp", 0), env);
	}
	file_name_buf = get_next_line(pipe_fd[0]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid, 0, 0);
	file_name = ft_substr(file_name_buf, 0, ft_strlen(file_name_buf) - 1);
	free(file_name_buf);
	return (file_name);
}

void	pipex_write_tmp_file(char *here_doc_file_name, char *limiter)
{
	int		here_doc_fd;
	char	*std_input;
	char	*std_input_cmp;

	here_doc_fd = open(here_doc_file_name, O_WRONLY);
	if (here_doc_fd == -1)
		exit(1);
	while (1)
	{
		std_input = get_next_line(0);
		if (!std_input)
			continue ;
		if (std_input[ft_strlen(std_input) - 1] == '\n')
			std_input_cmp = ft_substr(std_input, 0, ft_strlen(std_input) - 1);
		else
			ft_strlcpy(std_input_cmp, std_input, ft_strlen(std_input));
		if (!ft_strncmp(std_input_cmp, limiter, ft_strlen(limiter) + 1))
			break ;
		write(here_doc_fd, std_input, ft_strlen(std_input));
		free(std_input_cmp);
		free(std_input);
	}
	close(here_doc_fd);
	free(std_input_cmp);
	free(std_input);
}

void	pipex_set_fd_list_hd(t_fd_list *fd_list, char **av, int ac, char **env)
{
	int		pipe_idx;
	char	*here_doc_file_name;

	here_doc_file_name = pipex_get_here_doc_file_name(env);
	pipex_write_tmp_file(here_doc_file_name, av[2]);
	fd_list->file1_fd = open(here_doc_file_name, O_RDONLY);
	if (fd_list->file1_fd == -1)
		perror("");
	free(here_doc_file_name);
	fd_list->file2_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
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
