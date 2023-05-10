/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:47 by jnho              #+#    #+#             */
/*   Updated: 2023/01/27 15:51:28 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct s_cmd_list
{
	char	***cmd_list;
	char	**env;
	int		cmd_len;
}	t_cmd_list;

typedef struct s_fd_list
{
	int	file1_fd;
	int	file2_fd;
	int	**pipe_list;
}	t_fd_list;

void	free_2d_array(char **array);

void	pipex_set_cmd_list(t_cmd_list *cmd_list, char **av, int ac, char **env);
void	pipex_set_fd_list(t_fd_list *fd_list, char **av, int ac);

void	pipex_execute_cmd_list(t_cmd_list *cmd_list, t_fd_list *fd_list);

void	pipex_execve_cmd_error(char *cmd, int out_put_fd);

void	pipex_set_fd_list_hd(t_fd_list *fd_list, char **av, int ac, char **env);

#endif
