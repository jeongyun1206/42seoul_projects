/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:07:17 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/06 18:27:28 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_string(char **str, t_cmd *cmd, int flag)
{
	char	*start;
	char	*re;
	int		length;

	start = *str;
	while (**str == ' ')
			(*str)++;
	if (flag == 2)
		start = *str;
	while (**str)
	{
		if (flag == 0 && **str == '\'')
		{
			cmd->quot_flag[0] = 0;
			break ;
		}
		else if (flag == 1 && **str == '\"')
		{
			cmd->quot_flag[1] = 0;
			break ;
		}
		else if (flag == 2 && (**str == ' ' || **str == '>' || **str == '<'))
			break ;
		(*str)++;
	}
	length = *str - start;
	re = (char *)malloc(sizeof(char) * (length + 1));
	if (!re)
		exit(EXIT_FAILURE);
	ft_strlcpy(re, start, (length + 1));
	if (flag == 2)
		(*str)--;
	return (re);
}

void	get_input(char **str, t_cmd *cmd)
{
	(*str)++;
	if (**str == '<')
	{
		cmd->fds.here_doc_flag = 1;
		(*str)++;
		cmd->fds.limiter = get_string(str, cmd, 2);
	}
	else
		cmd->fds.here_doc_flag = 0;
	cmd->fds.input_file_name = get_string(str, cmd, 2);
}

void	get_output(char **str, t_cmd *cmd)
{
	(*str)++;
	if (**str == '>')
	{
		cmd->fds.file_append_flag = 1;
		(*str)++;
	}
	else
		cmd->fds.file_append_flag = 0;
	cmd->fds.output_file_name = get_string(str, cmd, 2);
}

void	set_flag(t_cmd *cmd, char c)
{
	if (c == '\'' && cmd->quot_flag[1] == 0)
		cmd->quot_flag[0] = 1;
	else if (c == '\"' && cmd->quot_flag[0] == 0)
		cmd->quot_flag[1] = 1;
	else if (c == '\'' && cmd->quot_flag[0] == 1)
		cmd->quot_flag[0] = 0;
	else if (c == '\"' && cmd->quot_flag[1] == 1)
		cmd->quot_flag[1] = 0;
}
