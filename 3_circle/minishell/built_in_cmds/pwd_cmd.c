/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:08:16 by jnho              #+#    #+#             */
/*   Updated: 2023/02/07 17:08:56 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    pwd_error_control(char **cmd_argv, int option)
{
    if (option == 1)
    {
        write(2, "pwd: bad option: -", 18);
        write(2, cmd_argv[1] + 1, 1);
        write(2, "\n", 1);
    }
    else
        write(2, "pwd: too many arguments\n", 24);
}

void    pwd_cmd(char **cmd_argv)
{
    char    pwd[PATH_MAX];

    if (argv_len(cmd_argv) != 1)
    {
        if (cmd_argv[1][0] == '-')
            pwd_error_control(cmd_argv, 1);
        else
            pwd_error_control(cmd_argv, 2);
        return ;
    }
    if (!getcwd(pwd, PATH_MAX))
    {
        perror("");
        return ;
    }
    ft_printf("%s\n", pwd);
}