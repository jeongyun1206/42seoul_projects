/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:10:13 by jnho              #+#    #+#             */
/*   Updated: 2023/02/05 16:52:30 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    env_error_control(char **cmd_argv, int option)
{
    if (option == 1)
    {
        write(2, "env: bad option: -", 18);
        write(2, cmd_argv[1] + 1, 1);
        write(2, "\n", 1);
    }
    else
        write(2, "env: too many arguments\n", 24);
}

void    env_cmd(char **cmd_argv, t_env *env_list)
{
    char    **env;
    int     idx;

    if (argv_len(cmd_argv) != 1)
    {
        if (cmd_argv[1][0] == '-')
            env_error_control(cmd_argv, 1);
        else
            env_error_control(cmd_argv, 2);
        return ;
    }
    env = env_list_to_char(env_list);
    idx = 0;
    while (env[idx])
    {
        write(1, env[idx], ft_strlen(env[idx]));
        write(1, "\n", 1);
        idx++;
    }
    free_argv_var(env);
}