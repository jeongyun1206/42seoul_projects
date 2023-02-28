/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:44:26 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/22 19:34:12 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_exception(char **str)
{
	char	*value;

	if (**str == '?')
		value = ft_itoa(g_exit_code);
	else
	{
		value = (char *)malloc(3);
		if (value == 0)
			exit(EXIT_FAILURE);
		value[0] = '$';
		value[1] = **str;
		value[2] = 0;
	}
	if (**str)
		(*str)++;
	return (value);
}

char	*get_env(char **str, t_cmd *cmd)
{
	char	*key;
	char	*start;
	int		length;
	char	*value;

	(*str)++;
	start = *str;
	if (!ft_isalpha(**str) && **str != '_')
		return (env_exception(str));
	export_cmd_key_move(str);
	length = *str - start;
	key = (char *)malloc(length + 1);
	if (!key)
		exit(EXIT_FAILURE);
	ft_strlcpy(key, start, length + 1);
	value = env_get_value_by_key(key, cmd->env_list);
	free(key);
	if (value == 0)
		return (NULL);
	return (ft_strdup(value));
}

void	export_cmd_key_move(char **key)
{
	if (!ft_isalpha(**key) && **key != '_')
		return ;
	(*key)++;
	while (**key)
	{
		if (!ft_isalnum(**key) && **key != '_')
			return ;
		(*key)++;
	}
}


char	*trans_str(char *str, t_cmd *cmd)
{
	char	*remain;
	char	*string;
	char	*tmp;

	remain = NULL;
	while (*str)
	{
		if (*str == '$')
			string = get_env(&str, cmd);
		else if (*str == '\'' || *str == '\"')
			string = get_quot(&str, cmd);
		else if (*str != '|')
			string = strcut_str(&str);
		if (remain && string)
		{
			tmp = ft_strjoin(remain, string);
			free(remain);
			free(string);
			remain = tmp;
		}
		else if (remain == NULL)
			remain = string;
	}
	return (remain);
}
