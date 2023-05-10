/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:03:00 by jnho              #+#    #+#             */
/*   Updated: 2023/01/27 16:26:44 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"
#include <unistd.h>

void	pipex_execve_cmd_error(char *cmd, int out_put_fd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	write(out_put_fd, "", 1);
	exit(127);
}
