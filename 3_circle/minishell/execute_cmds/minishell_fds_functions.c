/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fds_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:07:42 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 18:02:21 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    close_all_fds(t_cmd *cmd, int **pipe_arr)
{
    t_cmd   *cur_cmd;
    t_fds   *cur_fds;

    cur_cmd = cmd;
    while (cur_cmd)
    {
        cur_fds = &(cur_cmd->fds);
        if (cur_fds->here_doc_flag)
            unlink(cur_fds->input_file_name);
        if (cur_fds->input_file_fd != -1 && !cur_fds->input_pipe_flag)
            close(cur_fds->input_file_fd);
        if (cur_fds->output_file_fd != -1 && !cur_fds->output_pipe_flag)
            close(cur_fds->output_file_fd);
        if (cur_cmd->next)
        {
            close(pipe_arr[cur_cmd->pipe_idx][0]);
            close(pipe_arr[cur_cmd->pipe_idx][1]);
        }
        cur_cmd = cur_cmd->next;
    }
}

char	*get_here_doc_file_name(t_env *env_list)
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
		execve("/usr/bin/mktemp", ft_split("/usr/bin/mktemp", 0), env_list_to_char(env_list));
	}
	file_name_buf = get_next_line(pipe_fd[0]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid, 0, 0);
	file_name = ft_substr(file_name_buf, 0, ft_strlen(file_name_buf) - 1);
	free(file_name_buf);
	return (file_name);
}

void	write_here_doc_file(char *here_doc_file_name, char *limiter)
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

void    redirect_fds(t_cmd *exe_cmd, t_env *env_list, int **pipe_arr)
{
    t_fds   *fds;

    fds = &(exe_cmd->fds);
    if (!fds->input_file_name && fds->here_doc_flag)
    {
        fds->output_file_name = get_here_doc_file_name(env_list);
        write_here_doc_file(fds->output_file_name, fds->limiter);
        fds->output_file_fd = open(fds->output_file_name, O_RDONLY);
    }
    if (!fds->input_file_name && fds->input_pipe_flag)
        fds->input_file_fd = pipe_arr[exe_cmd->pipe_idx - 1][0];
    if (fds->input_file_name)
    {
        ft_printf(fds->input_file_name);
        fds->input_file_fd = open(fds->input_file_name, O_RDONLY);
        if (fds->input_file_fd == -1)
            perror("");
    }
    if (!fds->output_file_name && fds->output_pipe_flag)
        fds->output_file_fd = pipe_arr[exe_cmd->pipe_idx][1];
    if (fds->output_file_name && !fds->file_append_flag)
        fds->output_file_fd = open(fds->output_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fds->output_file_name && fds->file_append_flag)
        fds->output_file_fd = open(fds->output_file_name, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fds->input_file_fd, 0);
    dup2(fds->output_file_fd, 1);
}