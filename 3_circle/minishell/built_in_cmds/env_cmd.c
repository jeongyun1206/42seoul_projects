/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:10:13 by jnho              #+#    #+#             */
/*   Updated: 2023/02/21 19:50:16 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_error_control(char **cmd_argv, int option)
{
	if (option == 1)
	{
		write(2, "env: bad option: -", 18);
		write(2, cmd_argv[1] + 1, 1);
		write(2, "\n", 1);
	}
	else
		write(2, "env: too many arguments\n", 24);
	exit(EXECUTE_FAILED);
}

void	env_cmd(char **cmd_argv, t_env *env_list)
{
	t_env	*env_list_buf;

	if (argv_len(cmd_argv) != 1)
	{
		if (cmd_argv[1][0] == '-')
			env_error_control(cmd_argv, 1);
		else
			env_error_control(cmd_argv, 2);
		return ;
	}
	env_list_buf = env_list;
	while (env_list_buf)
	{
		if (env_list_buf->value && env_list_buf->value[0])
			ft_printf("%s=%s\n", env_list_buf->key, env_list_buf->value);
		env_list_buf = env_list_buf->next;
	}
	exit(EXECUTE_SUCCESSED);
}
