/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:07:17 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 18:49:46 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_endofstr(char **str, t_cmd *cmd)
{
	while (**str)
	{
		if (**str == '\'' || **str == '\"')
			set_flag(cmd, **str);
		else if ((cmd->quot_flag[0] == 0 && cmd->quot_flag[1] == 0) \
				&& (**str == ' ' || **str == '>' \
				|| **str == '<' || **str == '|'))
			break ;
		(*str)++;
	}
}

char	*get_string(char **str, t_cmd *cmd)
{
	char	*start;
	char	*re;
	char	*tmp;
	int		length;

	start = *str;
	while (**str == ' ')
			(*str)++;
	get_endofstr(str, cmd);
	length = *str - start;
	tmp = (char *)malloc(sizeof(char) * (length + 1));
	if (!tmp)
		exit(EXIT_FAILURE);
	ft_strlcpy(tmp, start, (length + 1));
	re = trans_str(tmp, cmd);
	free(tmp);
	return (re);
}

void	list_append(char **str, t_cmd *cmd, int flag)
{
	t_file	*node;
	char	*name;
	int		i;

	i = 0;
	name = get_string(str, cmd);
	node = ms_lstnew(name, flag % 2);
	if (flag == INPUT || flag == HEREDOC)
		ms_lstadd_back(&(cmd->fds.input_file_list), node);
	else
		ms_lstadd_back(&(cmd->fds.output_file_list), node);
}

void	get_input(char **str, t_cmd *cmd)
{
	int	heredoc;

	heredoc = 0;
	(*str)++;
	if (**str == '<')
	{
		(*str)++;
		heredoc = 1;
	}
	while (**str == ' ')
		(*str)++;
	if (heredoc == 1)
		list_append(str, cmd, HEREDOC);
	else
		list_append(str, cmd, INPUT);
}

void	get_output(char **str, t_cmd *cmd)
{
	int	append;

	append = 0;
	(*str)++;
	if (**str == '>')
	{
		(*str)++;
		append = 1;
	}
	while (**str == ' ')
		(*str)++;
	if (append == 1)
		list_append(str, cmd, APPEND);
	else
		list_append(str, cmd, OUTPUT);
}
