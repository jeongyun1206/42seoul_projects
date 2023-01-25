/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_control_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayongja <sayongja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:03:00 by jnho              #+#    #+#             */
/*   Updated: 2023/01/25 13:42:06 by sayongja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void    pipex_execve_cmd_error(char *cmd, int out_put_fd)
{
    write(2, cmd, ft_strlen(cmd));
    write(2, ": command not found\n", 20);
    write(out_put_fd, "", 1);
    exit(127);
}