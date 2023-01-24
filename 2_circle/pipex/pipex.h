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

#define READ 0
#define WRITE 1

typedef struct s_cmd_list
{
    char    ***cmd_list;
    char    **env;
    int     cmd_len;
}   t_cmd_list;

typedef struct s_fd_list
{
    int file1_fd;
    int file2_fd;
    int **pipe_list;
}   t_fd_list;

void    free_2d_array(char **array);

void    pipex_set_cmd_list(t_cmd_list *cmd_list, char **argv, int argc, char **env);
void    pipex_set_fd_list(t_fd_list *fd_list, char **argv, int argc);

void    pipex_execute_cmd_list(t_cmd_list *cmd_list, t_fd_list *fd_list);

void    pipex_execve_cmd_error(char *cmd, int out_put_fd);