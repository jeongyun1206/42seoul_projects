/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:22 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 16:40:56 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_flag(t_cmd *cmd, char c)
{
	if (c == '\'' && cmd->quot_flag[1] == 0 && cmd->quot_flag[0] == 0)
		cmd->quot_flag[0] = 1;
	else if (c == '\"' && cmd->quot_flag[0] == 0 && cmd->quot_flag[1] == 0)
		cmd->quot_flag[1] = 1;
	else if (c == '\'' && cmd->quot_flag[1] == 0 && cmd->quot_flag[0] == 1)
		cmd->quot_flag[0] = 0;
	else if (c == '\"' && cmd->quot_flag[0] == 0 && cmd->quot_flag[1] == 1)
		cmd->quot_flag[1] = 0;
}

void	get_pipetoken(t_cmd **cmd)
{
	if ((*cmd)->fds.input_file_list == NULL && (*cmd)->pipe_idx != 0)
		(*cmd)->fds.input_pipe_flag = 1;
	if ((*cmd)->fds.output_file_list == NULL)
		(*cmd)->fds.output_pipe_flag = 1;
	(*cmd)->next = init_struct((*cmd)->pipe_idx + 1, (*cmd)->env_list);
	(*cmd) = (*cmd)->next;
}

void	get_others(char **str, t_cmd *cmd)
{
	if (**str == '<')
		get_input(str, cmd);
	else if (**str == '>')
		get_output(str, cmd);
	else
		set_flag(cmd, **str);
}

int	redirect_flag(char c, int *flag0, int *flag1)
{		
	if (c == '>')
	{
		if (*flag1 != 0)
			return (1);
		if (++(*flag0) > 2)
			return (1);
	}
	else if (c == '<')
	{
		if (*flag0 != 0)
			return (2);
		if (++(*flag1) > 2)
			return (2);
	}
	return (0);
}
