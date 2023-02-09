/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:26 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/08 16:42:30 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**cmd_alloc(char **str, t_cmd *cmd, int count)
{
	char	**re;
	int		i;

	re = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count - 1)
	{
		re[i] = cmd->cmd[i];
		i++;
	}
	if (cmd->quot_flag[0] == 1)
		re[count - 1] = get_string(str, cmd, 0);
	else if (cmd->quot_flag[1] == 1)
		re[count - 1] = get_string(str, cmd, 1);
	else
		re[count - 1] = get_string(str, cmd, 2);
	re[count] = 0;
	if (cmd->cmd == NULL)
		return (re);
	free(cmd->cmd);
	return (re);
}

void	get_token(char *str, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (*str)
	{
		if (tmp->quot_flag[0] == 1 || tmp->quot_flag[1] == 1)
			tmp->cmd = cmd_alloc(&str, tmp, ++(tmp->cmd_count));
		else if (*str == '<')
			get_input(&str, tmp);
		else if (*str == '>')
			get_output(&str, tmp);
		else if (*str == '\"' || *str == '\'')
			set_flag(tmp, *str);
		else if (*str == ' ')
		{
			str++;
			continue ;
		}
		else if (*str == '|')
		{
			if (tmp->fds.input_file_list == NULL && tmp->pipe_idx != 0)
				tmp->fds.input_pipe_flag = 1;
			if (tmp->fds.output_file_list == NULL)
				tmp->fds.output_pipe_flag = 1;
			tmp->next = init_struct(tmp->pipe_idx + 1);
			tmp = tmp->next;
		}
		else
			tmp->cmd = cmd_alloc(&str, tmp, ++(tmp->cmd_count));
		str++;
	}
	if (tmp->fds.input_file_list == NULL && tmp->pipe_idx != 0)
		tmp->fds.input_pipe_flag = 1;
	if (tmp->fds.output_file_list == NULL && tmp->next)
		tmp->fds.output_pipe_flag = 1;
}

t_cmd	*init_struct(int num)
{
	t_cmd	*re;

	re = (t_cmd *)malloc(sizeof(t_cmd));
	ft_memset(re, 0, sizeof(t_cmd));
	re->pipe_idx = num;
	return (re);
}