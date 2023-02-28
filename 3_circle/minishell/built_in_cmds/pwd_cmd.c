/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:08:16 by jnho              #+#    #+#             */
/*   Updated: 2023/02/25 14:21:11 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd_error_control(char **cmd_argv, int option)
{
	if (option == 1)
	{
		write(2, "pwd: bad option: -", 18);
		write(2, cmd_argv[1] + 1, 1);
		write(2, "\n", 1);
	}
	else if (option == 2)
	{
		write(2, "getcwd: cannot access parent directories:", 41);
		write(2, "No such file or directory\n", 27);
	}
	else
		write(2, "pwd: too many arguments\n", 24);
	exit(EXECUTE_FAILED);
}

void	pwd_cmd(char **cmd_argv, t_env *env_list)
{
	char	pwd[PATH_MAX];
	char	*env_pwd_value;

	if (argv_len(cmd_argv) != 1)
	{
		if (cmd_argv[1][0] == '-')
			pwd_error_control(cmd_argv, 1);
		else
			pwd_error_control(cmd_argv, 0);
		return ;
	}
	if (!getcwd(pwd, PATH_MAX))
	{
		env_pwd_value = env_get_value_by_key("PWD", env_list);
		if (env_pwd_value)
			ft_printf("%s\n", env_pwd_value);
		else
			pwd_error_control(cmd_argv, 2);
	}
	else
		ft_printf("%s\n", pwd);
	exit(EXECUTE_SUCCESSED);
}
