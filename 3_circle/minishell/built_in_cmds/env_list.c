/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:59:34 by jnho              #+#    #+#             */
/*   Updated: 2023/02/21 19:17:21 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_add_node(char *key_value_string, t_env *env_list)
{
	t_env	*last_node;

	last_node = env_list;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = env_new_node(key_value_string);
	if (!last_node)
		exit(1);
}

char	*env_get_value_by_key(char *key, t_env *env_list)
{
	t_env	*env_buf;

	env_buf = env_list;
	while (env_buf)
	{
		if (!ft_strncmp(env_buf->key, key, ft_strlen(key) + 1))
			return (env_buf->value);
		env_buf = env_buf->next;
	}
	return (0);
}

int	env_delete_node_by_key(char *key, t_env *env_list)
{
	t_env	*cur_node;
	t_env	*prev_node;

	prev_node = 0;
	cur_node = env_list;
	while (cur_node)
	{
		if (!ft_strncmp(cur_node->key, key, ft_strlen(key) + 1))
		{
			if (prev_node)
				prev_node->next = cur_node->next;
			free_env_node(cur_node);
			return (1);
		}
		prev_node = cur_node;
		cur_node = cur_node->next;
	}
	return (0);
}

t_env	*env_char_to_list(char **env)
{
	int		env_idx;
	t_env	*env_list;
	t_env	*env_list_start;

	env_list_start = env_new_node(env[0]);
	env_list = env_list_start;
	env_idx = 1;
	while (env[env_idx])
	{
		env_list->next = env_new_node(env[env_idx]);
		env_list = env_list->next;
		env_idx++;
	}
	return (env_list_start);
}

char	**env_list_to_char(t_env *env_list)
{
	t_env	*env_list_buf;
	char	**env;
	char	*env_buff;
	int		env_idx;

	env = (char **)malloc(sizeof(char *) * (env_list_len(env_list) + 1));
	if (!env)
		exit(1);
	env_list_buf = env_list;
	env_idx = 0;
	while (env_list_buf)
	{
		env_buff = ft_strjoin(env_list_buf->key, "=");
		if (env_list_buf->value)
			env[env_idx] = ft_strjoin(env_buff, env_list_buf->value);
		else
			env[env_idx] = ft_strjoin(env_buff, "\'\'");
		free(env_buff);
		env_list_buf = env_list_buf->next;
		env_idx++;
	}
	env[env_idx] = 0;
	return (env);
}
