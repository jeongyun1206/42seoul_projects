/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:48:07 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 19:53:06 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_fork_no_cmds(t_cmd *exe_cmd, t_env *env_list, int **pipe_arr)
{
	redirect_fds(exe_cmd, env_list, pipe_arr, FORK_NO);
	execute_built_in_cmds(exe_cmd, env_list);
}

void	exit_cmd_line(t_cmd *cmd, pid_t *pid_arr, int **pipe_arr)
{
	close_all_fds(cmd, pipe_arr);
	wait_all_pid(pid_arr, lstlen(cmd));
	free_all_vars(cmd, pipe_arr, pid_arr);
}
