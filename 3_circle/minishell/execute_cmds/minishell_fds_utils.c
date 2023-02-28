/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fds_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:34:40 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 17:08:55 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*get_last_file(t_file *file_list)
{
	while (file_list && file_list->next)
		file_list = file_list->next;
	return (file_list);
}

void	free_file_list(t_file *file_list)
{
	t_file	*prev_file;

	while (file_list)
	{
		if (file_list->file_name)
			free(file_list->file_name);
		prev_file = file_list;
		file_list = file_list->next;
		free(prev_file);
	}
}

void	unlink_heredoc_files(t_file *input_file_list)
{
	while (input_file_list)
	{
		if (input_file_list->here_flag)
			unlink(input_file_list->file_name);
		input_file_list = input_file_list->next;
	}
}

void	close_all_fds(t_cmd *cmd, int **pipe_arr)
{
	t_cmd	*cur_cmd;
	t_fds	*cur_fds;
	t_file	*input_file_list;

	cur_cmd = cmd;
	while (cur_cmd)
	{
		cur_fds = &(cur_cmd->fds);
		input_file_list = cur_fds->input_file_list;
		unlink_heredoc_files(input_file_list);
		if ((cur_fds->input_file_fd < -1 || cur_fds->input_file_fd > 2)
			&& cur_fds->input_file_list)
			close(cur_fds->input_file_fd);
		if (cur_cmd->next)
			close(pipe_arr[cur_cmd->pipe_idx][0]);
		if ((cur_fds->output_file_fd < -1 || cur_fds->output_file_fd > 2)
			&& cur_fds->output_file_list)
			close(cur_fds->output_file_fd);
		if (cur_cmd->next)
			close(pipe_arr[cur_cmd->pipe_idx][1]);
		cur_cmd = cur_cmd->next;
	}
}
