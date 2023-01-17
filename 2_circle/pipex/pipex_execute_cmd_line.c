/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_cmd_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:43:18 by jnho              #+#    #+#             */
/*   Updated: 2023/01/17 16:57:12 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t    pipex_execute_cmd(t_cmd_line *cmd_line, int c_idx, int f_fd, int b_fd)
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
        dup2(f_fd, 0);
        dup2(b_fd, 1);
        execve(cmd_line->cmd_list[c_idx][0], cmd_line->cmd_list[c_idx], cmd_line->env);
        exit(0);
    }
    return (pid);  
}
// < file1 cmd1 | cmd2 > file2 

void    pipex_execute_cmd_line(t_cmd_line *cmd_line)
{
    int pid[2];

    pipe(cmd_line->pipe_fd);
    //pipex_execute_cmd(cmd_line, 0, cmd_line->file1_fd, cmd_line->file2_fd);
    pid[0] = pipex_execute_cmd(cmd_line, 0, cmd_line->file1_fd, cmd_line->pipe_fd[1]);
    pid[1] = pipex_execute_cmd(cmd_line, 1, cmd_line->pipe_fd[0], cmd_line->file2_fd);
}