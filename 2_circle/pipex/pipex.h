/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:47 by jnho              #+#    #+#             */
/*   Updated: 2023/01/17 16:37:10 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_cmd_line
{
    int     file1_fd;
    int     file2_fd;
    char    ***cmd_list;
    char    **env;
    int     pipe_fd[2];
}   t_cmd_line;

void    free_2d_array(char **array);

void    pipex_set_cmd_line(t_cmd_line *cmd_line, char **argv, int argc, char **env);

void    pipex_execute_cmd_line(t_cmd_line *cmd_line);