/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:05:31 by jnho              #+#    #+#             */
/*   Updated: 2023/02/09 12:42:08 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void    redirect_set_here_doc(t_file *input_file_list, t_env *env_list)
{
	char	*here_doc_file_name;

	while (input_file_list)
	{
		if (input_file_list->here_flag)
		{
    		here_doc_file_name = get_here_doc_file_name(env_list);
    		write_here_doc_file(here_doc_file_name, input_file_list->file_name);
			free(input_file_list->file_name);
			input_file_list->file_name = here_doc_file_name;
		}
		input_file_list = input_file_list->next;
	}
}