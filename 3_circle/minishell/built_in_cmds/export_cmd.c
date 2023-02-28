/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:13:19 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 13:05:59 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_error_control(char *env_key_value, int option)
{
	if (option == EXPORT_BAD_OPTION)
	{
		write(2, "export: bad option: -", 21);
		write(2, &env_key_value[1], 1);
		write(2, "\n", 1);
	}
	else if (option == EXPORT_NOT_VALID)
	{
		write(2, "export: '", 9);
		write(2, env_key_value, ft_strlen(env_key_value));
		write(2, "': not a valid identifier\n", 26);
	}
	g_exit_code = EXECUTE_FAILED;
}

void	sort_env(char **env)
{
	int		idx;
	int		not_sorted;
	char	*buff;

	not_sorted = argv_len(env) - 1;
	if (not_sorted < 1)
		return ;
	while (not_sorted)
	{
		idx = 1;
		while (idx < not_sorted)
		{
			if (ft_strncmp(env[idx], env[idx + 1], ft_strlen(env[idx]) + 1) > 0)
			{
				buff = env[idx];
				env[idx] = env[idx + 1];
				env[idx + 1] = buff;
			}
			idx++;
		}
		not_sorted--;
	}
}

void	export_cmd_with_no_arguments(t_env *env_list)
{
	char	**env;
	int		idx;

	env = env_list_to_char(env_list);
	sort_env(env);
	idx = 0;
	while (env[idx])
	{
		ft_printf("%s\n", env[idx]);
		idx++;
	}
	free_argv_var(env);
	exit(EXECUTE_SUCCESSED);
}

int	export_cmd_key_check(char *key)
{
	int	idx;

	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	idx = 1;
	while (key[idx])
	{
		if (!ft_isalnum(key[idx]) && key[0] != '_')
			return (0);
		idx++;
	}
	return (1);
}

void	export_cmd(char **cmd_argv, t_env *env_list)
{
	int		cmd_idx;
	char	*key;

	if (argv_len(cmd_argv) == 1)
		export_cmd_with_no_arguments(env_list);
	if (cmd_argv[1][0] == '-')
		return (export_error_control(cmd_argv[1], EXPORT_BAD_OPTION));
	cmd_idx = 1;
	while (cmd_argv[cmd_idx])
	{
		key = env_get_key_in_string(cmd_argv[cmd_idx]);
		if (!export_cmd_key_check(key))
			return (export_error_control(cmd_argv[cmd_idx], EXPORT_NOT_VALID));
		if (!env_get_value_by_key(key, env_list))
			env_add_node(cmd_argv[cmd_idx], env_list);
		else
			export_cmd_modify_env(key, cmd_argv[cmd_idx], env_list);
		free(key);
		cmd_idx++;
	}
	g_exit_code = EXECUTE_SUCCESSED;
}
