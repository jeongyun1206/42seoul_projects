/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell_execute_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:11 by jnho              #+#    #+#             */
/*   Updated: 2023/02/09 14:30:23 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int categorize_cmds(t_cmd *cmd)
{
    if (!ft_strncmp(cmd->cmd[0], "export", 7)
        || !ft_strncmp(cmd->cmd[0], "exit", 5)
        || !ft_strncmp(cmd->cmd[0], "cd", 3)
        || !ft_strncmp(cmd->cmd[0], "unset", 6))
        return (FORK_NO);
    if (!ft_strncmp(cmd->cmd[0], "echo", 5)
        || !ft_strncmp(cmd->cmd[0], "env", 4)
        || !ft_strncmp(cmd->cmd[0], "pwd", 4))
        return (2);
    return (1);
}

void    execute_built_in_cmds(t_cmd *cmd, t_env *env_list)
{
    if (!ft_strncmp(cmd->cmd[0], "echo", 5))
        echo_cmd(cmd->cmd);
    else if (!ft_strncmp(cmd->cmd[0], "cd", 3))
        cd_cmd(cmd->cmd, env_list);
    else if (!ft_strncmp(cmd->cmd[0], "env", 4))
        env_cmd(cmd->cmd, env_list);
    else if (!ft_strncmp(cmd->cmd[0], "exit", 5))
        exit_cmd();
    else if (!ft_strncmp(cmd->cmd[0], "pwd", 4))
        pwd_cmd(cmd->cmd);
    else if (!ft_strncmp(cmd->cmd[0], "export", 7))
        export_cmd(cmd->cmd, env_list);
    else if (!ft_strncmp(cmd->cmd[0], "unset", 6))
        unset_cmd(cmd->cmd, env_list);
}

void    set_binary_cmds(t_cmd *cmd, t_env *env_list)
{
    char    **path_list;
    char    *binary_cmd;
    char    *path_buf;
    int     path_idx;

    path_list = ft_split(env_get_value_by_key("PATH", env_list), ':');
    if (!path_list)
        return (execute_cmd_error_control(cmd));
    path_idx = 0;
    while (path_list[path_idx])
    {
        path_buf = ft_strjoin(path_list[path_idx], "/");
        binary_cmd = ft_strjoin(path_buf, cmd->cmd[0]);
        free(path_buf);
        if (!access(binary_cmd, 1))
            break ;
        free(binary_cmd);
        binary_cmd = 0;
        path_idx++;
    }
    if (!binary_cmd)
        return (execute_cmd_error_control(cmd));
    free(cmd->cmd[0]);
    cmd->cmd[0] = binary_cmd;
}

void    execute_fork_cmds(t_cmd *cmd, t_cmd *exe_cmd, t_env *env_list, int **pipe_arr)
{
    if (cmd->fds.input_file_fd == -1)
        exit(1);
    close_all_fds(cmd, pipe_arr);
    if (categorize_cmds(exe_cmd) == 2)
        execute_built_in_cmds(exe_cmd, env_list);
    else
    {
        if (access(exe_cmd->cmd[0], 1) == -1)
            set_binary_cmds(exe_cmd, env_list);
        execve(exe_cmd->cmd[0], exe_cmd->cmd, env_list_to_char(env_list));
    }
    exit(0);
}

void    execute_cmds(t_cmd *cmd, t_env *env_list)
{
    t_cmd   *exe_cmd;
    pid_t   *pid_arr;
    int     **pipe_arr;

    if (!cmd->cmd)
        return ;
    pid_arr = set_pid_arr(lstlen(cmd));
    pipe_arr = set_pipe_arr(lstlen(cmd));
    exe_cmd = cmd;
    while (exe_cmd)
    {
        if (categorize_cmds(exe_cmd) == FORK_NO)
        {
            redirect_fds(exe_cmd, env_list, pipe_arr, FORK_NO);
            execute_built_in_cmds(exe_cmd, env_list);
        }
        else
        {
            pid_arr[exe_cmd->pipe_idx] = fork();
            if (pid_arr[exe_cmd->pipe_idx] == 0)
            {
                redirect_fds(exe_cmd, env_list, pipe_arr, FORK_OK);
                execute_fork_cmds(cmd, exe_cmd, env_list, pipe_arr);
            }
        }
        exe_cmd = exe_cmd->next;
    }
    close_all_fds(cmd, pipe_arr);
    wait_all_pid(pid_arr, lstlen(cmd));
    free_all_vars(cmd, pipe_arr, pid_arr);
}