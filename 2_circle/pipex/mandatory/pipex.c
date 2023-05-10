/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:31 by jnho              #+#    #+#             */
/*   Updated: 2023/01/27 16:28:36 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#
#include "pipex.h"
#include "../libft/libft.h"

void	free_2d_array(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

void	pipex_set_fd_list(t_fd_list *fd_list, char **argv)
{
	fd_list->file1_fd = open(argv[1], O_RDONLY);
	if (fd_list->file1_fd == -1)
		perror("");
	fd_list->file2_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_list->file2_fd == -1)
		exit(1);
	pipe(fd_list->pipe);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd_list	cmd_list;
	t_fd_list	fd_list;

	if (argc != 5)
		exit(1);
	pipex_set_cmd_list(&cmd_list, argv, env);
	pipex_set_fd_list(&fd_list, argv);
	pipex_execute_cmd_list(&cmd_list, &fd_list);
}
