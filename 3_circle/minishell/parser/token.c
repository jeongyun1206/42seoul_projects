/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:07:17 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/08 16:09:08 by jnho             ###   ########seoul.kr  */
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

void	list_append(char **str, t_cmd *cmd, int flag)
{
	t_file	*node;
	char	*name;
	int		i;

	i = 0;
	if (cmd->quot_flag[0] == 1)
		name = get_string(str, cmd, SINGLE);
	else if (cmd->quot_flag[1] == 1)
		name = get_string(str, cmd, DOUBLE);
	else
		name = get_string(str, cmd, NONE);
	node = ms_lstnew(name, flag % 2);
	if (flag == INPUT || flag == HEREDOC)
		ms_lstadd_back(&(cmd->fds.input_file_list), node);
	else
		ms_lstadd_back(&(cmd->fds.output_file_list), node);
}

void	get_input(char **str, t_cmd *cmd)
{
	(*str)++;
	if (**str == '<')
	{
		(*str)++;
		list_append(str, cmd, HEREDOC);
		return ;
	}
	while (**str == ' ')
		(*str)++;
	if (**str == '\"' || **str == '\'')
	{
		set_flag(cmd, **str);
		(*str)++;
	}
	list_append(str, cmd, INPUT);
}

void	get_output(char **str, t_cmd *cmd)
{
	(*str)++;
	if (**str == '>')
	{
		(*str)++;
		list_append(str, cmd, APPEND);
		return ;
	}
	while (**str == ' ')
		(*str)++;
	if (**str == '\"' || **str == '\'')
	{
		set_flag(cmd, **str);
		(*str)++;
	}
	list_append(str, cmd, OUTPUT);
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
