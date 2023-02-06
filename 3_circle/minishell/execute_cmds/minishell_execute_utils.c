/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:41:30 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 17:58:15 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    free_all_vars(t_cmd *cmd, int **pipe_arr, pid_t *pid_arr)
{
    t_cmd   *prev_cmd;
    int     pipe_len;
    int     idx;

    free(pid_arr);
    pipe_len = lstlen(cmd);
    idx = 0;
    while (idx < pipe_len - 1)
        free(pipe_arr[idx++]);
    free(pipe_arr);
    while (cmd)
    {
        free_argv_var(cmd->cmd);
        free(cmd->fds.input_file_name);
        free(cmd->fds.output_file_name);
        prev_cmd = cmd;
        cmd = cmd->next;
        free(prev_cmd);
    }
}

pid_t   *set_pid_arr(size_t cmd_len)
{
    pid_t   *pid_arr;
    
    pid_arr = (pid_t *)malloc(sizeof(pid_t) * cmd_len);
    if (!pid_arr)
        exit(1);
    return (pid_arr);
}

int **set_pipe_arr(size_t cmd_len)
{
    size_t  pipe_idx;
    int     **pipe_arr;
    
    pipe_arr = (int **)malloc(sizeof(int *) * (cmd_len - 1));
    if (!pipe_arr)
        exit(1);
    pipe_idx = 0;
    while (pipe_idx < cmd_len - 1)
    {
        pipe_arr[pipe_idx] = (int *)malloc(sizeof(int) * 2);
        if (!pipe_arr[pipe_idx])
            exit(1);
        if (pipe(pipe_arr[pipe_idx]) == -1)
            exit(1);
        pipe_idx++;
    }
    return (pipe_arr);
}

void    wait_all_pid(pid_t *pid_arr, size_t cmd_len)
{
    size_t  pid_idx;

    pid_idx = 0;
    while (pid_idx < cmd_len)
    {
        waitpid(pid_arr[pid_idx], 0, 0);
        pid_idx++;
    }
}