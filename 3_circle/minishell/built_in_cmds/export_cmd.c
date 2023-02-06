/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:13:19 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 16:31:09 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    export_error_control(char **cmd_argv)
{
    write(2, "export: bad option: -", 21);
    write(2, &cmd_argv[1][1], 1);
    write(2, "\n", 1);
}

void    export_cmd(char **cmd_argv, t_env *env_list)
{
    int     cmd_idx;
    char    *key;

    if (argv_len(cmd_argv) == 1)
    {
        env_cmd(cmd_argv, env_list);
        return ;
    }
    if (cmd_argv[1][0] == '-')
    {
        export_error_control(cmd_argv);
        return ;
    }
    cmd_idx = 1;
    while (cmd_argv[cmd_idx])
    {
        key = env_get_key_in_string(cmd_argv[cmd_idx]);
        if (!env_get_value_by_key(key, env_list))
            env_add_node(cmd_argv[cmd_idx], env_list);
        cmd_idx++;
        free(key);
    }
}