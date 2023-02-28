/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:50:14 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 18:03:21 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quoto_check(char *str)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (*str == '\'' && (flag & 2) == 0)
			flag ^= 1;
		else if (*str == '\"' && (flag & 1) == 0)
			flag ^= 2;
		str++;
	}
	return (flag);
}

int	pipe_check(char *str)
{
	int	flag;
	int	length;

	flag = -1;
	length = 0;
	while (*str)
	{
		length++;
		if (*str == '|' && flag != -1)
			flag++;
		else if (*str == ' ')
		{
			str++;
			continue ;
		}
		else if (*str != '|')
			flag = 0;
		if (flag == 2 || flag == -1)
			break ;
		str++;
	}
	if ((flag == 2 || flag == -1) && length > 0)
		return (1);
	return (0);
}

int	redirect_check(char *str)
{
	int	flag[2];
	int	re;

	flag[0] = 0;
	flag[1] = 0;
	re = 0;
	while (*str)
	{
		if (*str == '>' || *str == '<')
			re = redirect_flag(*str, &flag[0], &flag[1]);
		else if (*str == ' ')
		{
			str++;
			continue ;
		}
		else
		{
			flag[0] = 0;
			flag[1] = 0;
		}
		if (re != 0)
			return (re);
		str++;
	}
	return (0);
}

int	syntax_check(char *str)
{
	int	flag;

	flag = redirect_check(str);
	if (quoto_check(str) != 0)
	{
		write(2, "bash: syntax error near unexpected token \'newline\'\n", 51);
		return (1);
	}
	if (pipe_check(str) != 0)
	{
		write(2, "bash: syntax error near unexpected token \'|\'\n", 45);
		return (1);
	}
	if (flag == 1)
	{
		write(2, "bash: syntax error near unexpected token \'>\'\n", 45);
		return (1);
	}
	if (flag == 2)
	{
		write(2, "bash: syntax error near unexpected token \'<\'\n", 45);
		return (1);
	}
	return (0);
}

int	cmd_syntaxcheck(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->fds.input_file_list && \
			cmd->fds.input_file_list->file_name == NULL)
		{
			write(2, "bash: syntax error near unexpected token \'newline\'\n", 51);
			return (1);
		}
		if (cmd->fds.output_file_list && \
			cmd->fds.output_file_list->file_name == NULL)
		{
			write(2, "bash: syntax error near unexpected token \'newline\'\n", 51);
			return (1);
		}
		cmd = cmd->next;
	}
	return (0);
}
