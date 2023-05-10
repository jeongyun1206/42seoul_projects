/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_cmd_line_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:43:18 by jnho              #+#    #+#             */
/*   Updated: 2023/02/08 13:57:35 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

void	pipex_fd_close(t_fd_list *fd_list, int cmd_len)
{
	int	pipe_idx;

	close(fd_list->file1_fd);
	close(fd_list->file2_fd);
	pipe_idx = 0;
	while (pipe_idx < cmd_len - 1)
	{
		close(fd_list->pipe_list[pipe_idx][0]);
		close(fd_list->pipe_list[pipe_idx][1]);
		pipe_idx++;
	}
}

pid_t	pipex_redirect_l(t_cmd_list *cmd_list, t_fd_list *fd_list, int cmd_idx)
{
	pid_t	pid;
	int		*pipe_write;
	char	**cmd;

	pipe_write = fd_list->pipe_list[cmd_idx];
	pid = fork();
	if (pid == 0)
	{
		if (fd_list->file1_fd < 0)
			exit(1);
		dup2(fd_list->file1_fd, 0);
		dup2(pipe_write[1], 1);
		pipex_fd_close(fd_list, cmd_list->cmd_len);
		cmd = cmd_list->cmd_list[cmd_idx];
		if (execve(cmd[0], cmd, cmd_list->env) == -1)
			pipex_execve_cmd_error(cmd[0], pipe_write[1]);
	}
	return (pid);
}

pid_t	pipex_pipe_both(t_cmd_list *cmd_list, t_fd_list *fd_list, int cmd_idx)
{
	pid_t	pid;
	int		*pipe_read;
	int		*pipe_write;
	char	**cmd;

	pipe_read = fd_list->pipe_list[cmd_idx - 1];
	pipe_write = fd_list->pipe_list[cmd_idx];
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_read[0], 0);
		dup2(pipe_write[1], 1);
		pipex_fd_close(fd_list, cmd_list->cmd_len);
		cmd = cmd_list->cmd_list[cmd_idx];
		if (execve(cmd[0], cmd, cmd_list->env) == -1)
			pipex_execve_cmd_error(cmd[0], fd_list->pipe_list[cmd_idx][1]);
	}
	return (pid);
}

pid_t	pipex_redirect_r(t_cmd_list *cmd_list, t_fd_list *fd_list, int cmd_idx)
{
	pid_t	pid;
	int		*pipe_read;
	char	**cmd;

	pipe_read = fd_list->pipe_list[cmd_idx - 1];
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_read[0], 0);
		dup2(fd_list->file2_fd, 1);
		pipex_fd_close(fd_list, cmd_list->cmd_len);
		cmd = cmd_list->cmd_list[cmd_idx];
		if (execve(cmd[0], cmd, cmd_list->env) == -1)
			pipex_execve_cmd_error(cmd[0], fd_list->file2_fd);
	}
	return (pid);
}

void	pipex_execute_cmd_list(t_cmd_list *cmd_list, t_fd_list *fd_list)
{
	int		cmd_idx;
	pid_t	*pid_list;

	cmd_idx = 0;
	pid_list = (pid_t *)malloc(sizeof(pid_t) * cmd_list->cmd_len);
	if (!pid_list)
		exit(1);
	pid_list[cmd_idx] = pipex_redirect_l(cmd_list, fd_list, cmd_idx);
	cmd_idx++;
	while (cmd_idx < cmd_list->cmd_len - 1)
	{
	pid_list[cmd_idx] = pipex_pipe_both(cmd_list, fd_list, cmd_idx);
	cmd_idx++;
	}
	pid_list[cmd_idx] = pipex_redirect_r(cmd_list, fd_list, cmd_idx);
	pipex_fd_close(fd_list, cmd_list->cmd_len);
	cmd_idx = 0;
	while (cmd_idx < cmd_list->cmd_len)
	{
		waitpid(pid_list[cmd_idx], 0, 0);
		cmd_idx++;
	}
	exit(0);
}
