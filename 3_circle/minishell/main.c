/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:29:33 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 18:34:56 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
    t_env   *env_list;

    argc = 0;
    argv = 0;
    env_list = env_char_to_list(env);
	cmd = init_struct(0);

	get_token("ls -al | cat > a | cat -al >> a << b", cmd);
    execute_cmds(cmd, env_list);
}
