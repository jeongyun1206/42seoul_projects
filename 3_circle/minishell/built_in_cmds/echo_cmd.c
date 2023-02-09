/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:05:27 by jnho              #+#    #+#             */
/*   Updated: 2023/02/07 12:35:57 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    echo_cmd(char **cmd_argv)
{
    int option;
    int cmd_idx;

    cmd_idx = 1;
    option = ft_strncmp(cmd_argv[cmd_idx], "-n", 3);
    while (!ft_strncmp(cmd_argv[cmd_idx], "-n", 3))
        cmd_idx++;
    while (cmd_argv[cmd_idx])
    {
        write(1, cmd_argv[cmd_idx], ft_strlen(cmd_argv[cmd_idx]));
        if (cmd_argv[cmd_idx + 1])
            write(1, " ", 1);
        cmd_idx++;
    }
    if (option)
        write(1, "\n", 1);
}