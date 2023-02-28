/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:05:31 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 19:53:29 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_heredoc_file_name(t_env *env_list)
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
		execve("/usr/bin/mktemp", ft_split("/usr/bin/mktemp", 0), \
		env_list_to_char(env_list));
	}
	file_name_buf = get_next_line(pipe_fd[0]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid, 0, 0);
	file_name = ft_substr(file_name_buf, 0, ft_strlen(file_name_buf) - 1);
	free(file_name_buf);
	return (file_name);
}

void	write_heredoc_file(char *heredoc_file_name, char *limiter)
{
	int		heredoc_fd;
	char	*std_input;
	char	*std_input_cmp;

	set_signal(DEFAULT);
	heredoc_fd = open(heredoc_file_name, O_WRONLY);
	if (heredoc_fd == -1)
		exit(1);
	while (1)
	{
		std_input = get_next_line(0);
		if (!std_input)
			break ;
		if (std_input[ft_strlen(std_input) - 1] == '\n')
			std_input_cmp = ft_substr(std_input, 0, ft_strlen(std_input) - 1);
		else
			ft_strlcpy(std_input_cmp, std_input, ft_strlen(std_input));
		if (!ft_strncmp(std_input_cmp, limiter, ft_strlen(limiter) + 1))
			break ;
		write(heredoc_fd, std_input, ft_strlen(std_input));
		free(std_input_cmp);
		free(std_input);
	}
	close(heredoc_fd);
	exit(0);
}

void	redirect_set_heredoc(t_file *input_file_list, t_env *env_list)
{
	char	*heredoc_file_name;
	pid_t	pid;
	int		status;

	while (input_file_list)
	{
		if (input_file_list->here_flag)
		{
			heredoc_file_name = get_heredoc_file_name(env_list);
			pid = fork();
			if (pid == 0)
				write_heredoc_file(heredoc_file_name, \
				input_file_list->file_name);
			set_signal(IGNORE);
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				g_exit_code = WEXITSTATUS(status);
			if (WIFSIGNALED(status))
				g_exit_code = 1;
			free(input_file_list->file_name);
			input_file_list->file_name = heredoc_file_name;
		}
		input_file_list = input_file_list->next;
	}
	waitpid(pid, 0, 0);
}
