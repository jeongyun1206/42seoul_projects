/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:47 by jnho              #+#    #+#             */
/*   Updated: 2023/01/24 14:12:34 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_cmd_list
{
    char    **cmd_list[2];
    char    **env;
}   t_cmd_list;

typedef struct s_fd_list
{
    int file1_fd;
    int file2_fd;
    int pipe[2];
}   t_fd_list;

void    free_2d_array(char **array);

void    pipex_set_cmd_list(t_cmd_list *cmd_list, char **argv, char **env);

void    pipex_execute_cmd_list(t_cmd_list *cmd_list, t_fd_list *fd_list);

void    pipex_execve_cmd_error(char *cmd, int out_put_fd);