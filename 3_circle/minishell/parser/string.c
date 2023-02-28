/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:54:07 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 19:32:37 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*strcut_str(char **str)
{
	char	*string;
	char	*start;
	int		length;

	start = *str;
	while (**str != 0 && **str != '$' && **str != '\'' && **str != '\"')
		(*str)++;
	length = *str - start;
	string = malloc(length + 1);
	if (!string)
		exit(EXIT_FAILURE);
	ft_strlcpy(string, start, length + 1);
	return (string);
}

char	*strcut_str_double(char **str)
{
	char	*string;
	char	*start;
	int		length;

	start = *str;
	while (**str != '\"' && **str != '$')
		(*str)++;
	length = *str - start;
	string = malloc(length + 1);
	if (!string)
		exit(EXIT_FAILURE);
	ft_strlcpy(string, start, length + 1);
	return (string);
}

char	*get_quot(char **str, t_cmd *cmd)
{
	char	*string;

	if (**str == '\'')
		string = get_single(str);
	else if (**str == '\"')
		string = get_double(str, cmd);
	else
		string = NULL;
	return (string);
}

char	*get_single(char **str)
{
	char	*string;
	char	*start;
	int		length;

	(*str)++;
	start = *str;
	while (**str != '\'')
		(*str)++;
	length = *str - start;
	string = malloc(length + 1);
	if (!string)
		exit(EXIT_FAILURE);
	ft_strlcpy(string, start, length + 1);
	(*str)++;
	return (string);

}

char	*get_double(char **str, t_cmd *cmd)
{
	char	*remain;
	char	*string;
	char	*tmp;

	(*str)++;
	remain = NULL;
	while (**str != '\"')
	{
		if (**str == '$')
		{
			string = get_env(str, cmd);
		}
		else
			string = strcut_str_double(str);
		if (remain)
		{
			tmp = ft_strjoin(remain, string);
			free(remain);
			free(string);
			remain = tmp;
		}
		else
			remain = string;
	}
	(*str)++;
	return (remain);
}
