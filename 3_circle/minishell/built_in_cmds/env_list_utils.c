/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:51:37 by jnho              #+#    #+#             */
/*   Updated: 2023/02/05 15:13:15 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env   *env_new_node(char *env)
{
    size_t  idx;
    t_env   *env_list;

    env_list = (t_env *)malloc(sizeof(t_env));
    if (!env_list)
        exit(1);
    idx = 0;
    while (env[idx] != '=' && env[idx])
        idx++;
    env_list->key = ft_substr(env, 0, idx);
    if (!env_list->key)
        exit(1);
    if (env[idx] == '=')
        env_list->value = ft_substr(env, idx + 1, ft_strlen(env));
    else
        env_list->value = ft_strdup("");
    if (!env_list->value)
        exit(1);
    env_list->next = 0;
    return (env_list);
}

void    free_env_node(t_env *env_node)
{
    free(env_node->key);
    free(env_node->value);
    free(env_node);
}

int env_list_len(t_env *env_list)
{
    int env_len;

    env_len = 0;
    while (env_list)
    {
        env_len++;
        env_list = env_list->next;
    }
    return (env_len);
}

char    *env_get_key_in_string(char *str)
{
    size_t  idx;
    char    *key;

    idx = 0;
    while (str[idx] != '=' && str[idx])
        idx++;
    key = ft_substr(str, 0, idx);
    if (!key)
        exit(1);
    return (key);
}