/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:11 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 19:52:50 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	categorize_cmds(t_cmd *cmd)
{
	if (!cmd->cmd)
		return (-1);
	if ((!ft_strncmp(cmd->cmd[0], "export", 7) && argv_len(cmd->cmd) != 1)
		|| !ft_strncmp(cmd->cmd[0], "exit", 5)
		|| !ft_strncmp(cmd->cmd[0], "cd", 3)
		|| !ft_strncmp(cmd->cmd[0], "unset", 6))
		return (FORK_NO);
	if ((!ft_strncmp(cmd->cmd[0], "export", 7) && argv_len(cmd->cmd) == 1)
		|| !ft_strncmp(cmd->cmd[0], "echo", 5)
		|| !ft_strncmp(cmd->cmd[0], "env", 4)
		|| !ft_strncmp(cmd->cmd[0], "pwd", 4))
		return (2);
	return (1);
}

void	execute_built_in_cmds(t_cmd *cmd, t_env *env_list)
{
	if (!cmd->cmd)
		return ;
	if (!ft_strncmp(cmd->cmd[0], "echo", 5))
		echo_cmd(cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "cd", 3))
		cd_cmd(cmd->cmd, env_list);
	else if (!ft_strncmp(cmd->cmd[0], "env", 4))
		env_cmd(cmd->cmd, env_list);
	else if (!ft_strncmp(cmd->cmd[0], "exit", 5))
		exit_cmd(cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "pwd", 4))
		pwd_cmd(cmd->cmd, env_list);
	else if (!ft_strncmp(cmd->cmd[0], "export", 7))
		export_cmd(cmd->cmd, env_list);
	else if (!ft_strncmp(cmd->cmd[0], "unset", 6))
		unset_cmd(cmd->cmd, env_list);
}

void	set_binary_cmds(t_cmd *cmd, t_env *env_list)
{
	char	**path_list;
	char	*binary_cmd;
	char	*path_buf;
	int		path_idx;

	path_list = ft_split(env_get_value_by_key("PATH", env_list), ':');
	if (!path_list)
		return (execute_cmd_error_control(cmd, 127));
	path_idx = 0;
	while (path_list[path_idx])
	{
		path_buf = ft_strjoin(path_list[path_idx], "/");
		binary_cmd = ft_strjoin(path_buf, cmd->cmd[0]);
		free(path_buf);
		if (!access(binary_cmd, 0))
			break ;
		free(binary_cmd);
		binary_cmd = 0;
		path_idx++;
	}
	if (!binary_cmd)
		return (execute_cmd_error_control(cmd, COMMAND_NOT_FOUND));
	free(cmd->cmd[0]);
	cmd->cmd[0] = binary_cmd;
}

void	execute_fork_cmds(t_cmd *cmd, t_cmd *e_cmd, t_env *e_list, int **p_arr)
{
	set_signal(DEFAULT);
	if (cmd->fds.input_file_fd == -1)
		exit(1);
	close_all_fds(cmd, p_arr);
	if (categorize_cmds(e_cmd) == 2)
		execute_built_in_cmds(e_cmd, e_list);
	else
	{
		if (!access(e_cmd->cmd[0], 0) && access(e_cmd->cmd[0], 1) == -1)
			execute_cmd_error_control(cmd, PERMISSION_DEINED);
		else if (access(e_cmd->cmd[0], 0) == -1)
			set_binary_cmds(e_cmd, e_list);
		if (!access(e_cmd->cmd[0], 0) && access(e_cmd->cmd[0], 1) == -1)
			execute_cmd_error_control(cmd, PERMISSION_DEINED);
		execve(e_cmd->cmd[0], e_cmd->cmd, env_list_to_char(e_list));
	}
	exit(0);
}

void	execute_cmds(t_cmd *cmd, t_env *env_list)
{
	t_cmd	*exe_cmd;
	pid_t	*pid_arr;
	int		**pipe_arr;

	pid_arr = set_pid_arr(lstlen(cmd));
	pipe_arr = set_pipe_arr(lstlen(cmd));
	exe_cmd = cmd;
	while (exe_cmd)
	{
		if (categorize_cmds(exe_cmd) <= FORK_NO)
			execute_fork_no_cmds(exe_cmd, env_list, pipe_arr);
		else if (categorize_cmds(exe_cmd) > FORK_NO)
		{
			pid_arr[exe_cmd->pipe_idx] = fork();
			if (pid_arr[exe_cmd->pipe_idx] == 0)
			{
				set_signal(DEFAULT);
				redirect_fds(exe_cmd, env_list, pipe_arr, FORK_OK);
				execute_fork_cmds(cmd, exe_cmd, env_list, pipe_arr);
			}
			set_signal(IGNORE);
		}
		exe_cmd = exe_cmd->next;
	}
	exit_cmd_line(cmd, pid_arr, pipe_arr);
}
