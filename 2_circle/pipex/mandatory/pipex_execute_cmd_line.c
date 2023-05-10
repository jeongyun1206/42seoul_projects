/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_cmd_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:43:18 by jnho              #+#    #+#             */
/*   Updated: 2023/01/27 16:27:27 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void	pipex_fd_close(t_fd_list *fd_list)
{
	close(fd_list->file1_fd);
	close(fd_list->file2_fd);
	close(fd_list->pipe[0]);
	close(fd_list->pipe[1]);
}

pid_t	pipex_redirect_l(t_cmd_list *cmd_list, t_fd_list *fd_list, int cmd_idx)
{
	pid_t	pid;
	int		*pipe_write;
	char	**cmd;

	pipe_write = fd_list->pipe;
	pid = fork();
	if (pid == 0)
	{
		if (fd_list->file1_fd < 0)
			exit(1);
		dup2(fd_list->file1_fd, 0);
		dup2(pipe_write[1], 1);
		pipex_fd_close(fd_list);
		cmd = cmd_list->cmd_list[cmd_idx];
		if (execve(cmd[0], cmd, cmd_list->env) == -1)
			pipex_execve_cmd_error(cmd[0], pipe_write[1]);
	}
	return (pid);
}

pid_t	pipex_redirect_r(t_cmd_list *cmd_list, t_fd_list *fd_list, int cmd_idx)
{
	pid_t	pid;
	int		*pipe_read;
	char	**cmd;

	pipe_read = fd_list->pipe;
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_read[0], 0);
		dup2(fd_list->file2_fd, 1);
		pipex_fd_close(fd_list);
		cmd = cmd_list->cmd_list[cmd_idx];
		if (execve(cmd[0], cmd, cmd_list->env) == -1)
			pipex_execve_cmd_error(cmd[0], fd_list->file2_fd);
	}
	return (pid);
}

void	pipex_execute_cmd_list(t_cmd_list *cmd_list, t_fd_list *fd_list)
{
	pid_t	pid_list[2];

	pid_list[0] = pipex_redirect_l(cmd_list, fd_list, 0);
	pid_list[1] = pipex_redirect_r(cmd_list, fd_list, 1);
	pipex_fd_close(fd_list);
	waitpid(pid_list[0], 0, 0);
	waitpid(pid_list[1], 0, 0);
	exit(0);
}
