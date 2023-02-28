/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:26 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 18:51:55 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**cmd_alloc(char **str, t_cmd *cmd, int count)
{
	char	**re;
	int		i;

	re = (char **)malloc(sizeof(char *) * (count + 1));
	if (!re)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < count - 1)
	{
		re[i] = cmd->cmd[i];
		i++;
	}
	re[count - 1] = get_string(str, cmd);
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
		if (*str == '<')
			get_input(&str, tmp);
		else if (*str == '>')
			get_output(&str, tmp);
		else if (*str == ' ')
			str++;
		else if (*str == '|')
		{
			get_pipetoken(&tmp);
			str++;
		}
		else
			tmp->cmd = cmd_alloc(&str, tmp, ++(tmp->cmd_count));
	}
	if (tmp->fds.input_file_list == NULL && tmp->pipe_idx != 0)
		tmp->fds.input_pipe_flag = 1;
	if (tmp->fds.output_file_list == NULL && tmp->next)
		tmp->fds.output_pipe_flag = 1;
}

t_cmd	*init_struct(int num, t_env *env_list)
{
	t_cmd	*re;

	re = (t_cmd *)malloc(sizeof(t_cmd));
	ft_memset(re, 0, sizeof(t_cmd));
	re->env_list = env_list;
	re->pipe_idx = num;
	return (re);
}
