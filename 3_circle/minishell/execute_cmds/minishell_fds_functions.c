/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fds_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:07:42 by jnho              #+#    #+#             */
/*   Updated: 2023/02/09 14:16:54 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    redirect_input_file(t_fds *fds, t_env *env_list, int pipe_fd)
{
    t_file  *last_input_file;

    fds->input_file_fd = 0;
    if (fds->input_pipe_flag && pipe_fd != -1)
        fds->input_file_fd = pipe_fd;
    redirect_set_here_doc(fds->input_file_list, env_list);
    last_input_file = get_last_file(fds->input_file_list);
    if (last_input_file)
        fds->input_file_fd = open(last_input_file->file_name, O_RDONLY);
    if (fds->input_file_fd == -1)
    {
        write(2, last_input_file->file_name, ft_strlen(last_input_file->file_name));
        write(2, ": ", 2);
        perror("");
    }
}

void    redirect_output_file(t_fds *fds, int pipe_fd)
{
    t_file  *output_file_list;
    char    *file_name;
    int     file_fd;

    fds->output_file_fd = 1;
    if (fds->output_pipe_flag && pipe_fd != -1)
        fds->output_file_fd = pipe_fd;
    output_file_list = fds->output_file_list;
    while (output_file_list)
    {
        file_name = output_file_list->file_name;
        if (!output_file_list->here_flag)
            file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (output_file_list->here_flag)
            file_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0666);
        if (!output_file_list->next)
        {
            fds->output_file_fd = file_fd;
            return ;
        }
        close(file_fd);
        output_file_list = output_file_list->next;
    }
}

void    redirect_fds(t_cmd *exe_cmd, t_env *env_list, int **pipe_arr, int fork)
{
    t_fds   *fds;

    fds = &(exe_cmd->fds);
    if (exe_cmd->pipe_idx)
        redirect_input_file(fds, env_list, pipe_arr[exe_cmd->pipe_idx - 1][0]);
    else
        redirect_input_file(fds, env_list, -1);
    if (exe_cmd->next)
        redirect_output_file(fds, pipe_arr[exe_cmd->pipe_idx][1]);
    else
        redirect_output_file(fds, -1);
    if (fork  && fds->input_file_fd != 0)
        dup2(fds->input_file_fd, 0);
    if (fork && fds->input_file_fd != 1)
        dup2(fds->output_file_fd, 1);
}