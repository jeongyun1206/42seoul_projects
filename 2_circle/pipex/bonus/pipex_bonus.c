/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:31 by jnho              #+#    #+#             */
/*   Updated: 2023/01/27 16:26:26 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
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

int	main(int ac, char **av, char **env)
{
	t_cmd_list	cmd_list;
	t_fd_list	fd_list;

	if (ac < 5)
		exit(1);
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex_set_cmd_list(&cmd_list, av + 1, ac - 1, env);
		pipex_set_fd_list_hd(&fd_list, av, ac, env);
	}
	else
	{
		pipex_set_cmd_list(&cmd_list, av, ac, env);
		pipex_set_fd_list(&fd_list, av, ac);
	}
	pipex_execute_cmd_list(&cmd_list, &fd_list);
	exit(0);
}
