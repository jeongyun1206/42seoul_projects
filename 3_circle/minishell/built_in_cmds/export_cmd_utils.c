/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:23:33 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 13:09:11 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_cmd_modify_env(char *key, char *key_value, t_env *env_list)
{
	char	*value;

	value = ft_strchr(key_value, '=');
	if (value)
		value = ft_strdup(value);
	else
		value = ft_strdup("");
	env_change_value(key, value, env_list);
}
