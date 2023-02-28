/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:26 by jnho              #+#    #+#             */
/*   Updated: 2023/02/20 14:19:00 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_error_control(char **cmd_argv, int option)
{
	if (option == 1)
	{
		write(2, "unset: bad option: -", 18);
		write(2, cmd_argv[1] + 1, 1);
		write(2, "\n", 1);
	}
	else
		write(2, "unset: not enough arguments\n", 28);
	g_exit_code = EXECUTE_FAILED;
}

void	unset_cmd(char **cmd_argv, t_env *env_list)
{
	int	key_idx;

	if (argv_len(cmd_argv) == 1)
	{
		unset_error_control(cmd_argv, 2);
		return ;
	}
	if (cmd_argv[1][0] == '-')
	{
		unset_error_control(cmd_argv, 1);
		return ;
	}
	key_idx = 1;
	while (cmd_argv[key_idx])
	{
		env_delete_node_by_key(cmd_argv[key_idx], env_list);
		key_idx++;
	}
	g_exit_code = EXECUTE_SUCCESSED;
}
