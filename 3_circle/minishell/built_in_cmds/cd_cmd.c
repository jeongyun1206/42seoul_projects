/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:26 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 12:57:41 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_error_control(char *cmd_path, int error_code)
{
	if (error_code == CD_ERROR_NO_SUCH_FILE)
	{
		write(2, "cd: ", 3);
		write(2, cmd_path, ft_strlen(cmd_path));
		write(2, ": No such file or directory\n", 28);
	}
	else if (error_code == CD_ERROR_GETCWD)
	{
		write(2, "cd: error retrieving current directory: ", 40);
		write(2, "getcwd: cannot access parent directories: ", 42);
		write(2, "No such file or directory\n", 26);
	}
	else if (error_code == CD_ERROR_HOME_NOT_SET)
		write(2, "cd: HOME not set\n", 17);
	g_exit_code = EXIT_FAILURE;
}

int	cd_cmd_set_env_pwd_oldpwd(char *cmd_path, t_env *env_list)
{
	char	*old_pwd;
	char	pwd[PATH_MAX];

	old_pwd = ft_strdup(env_get_value_by_key("PWD", env_list));
	if (!env_change_value("OLDPWD", old_pwd, env_list))
		env_add_node(ft_strjoin("OLDPWD=", old_pwd), env_list);
	if (!getcwd(pwd, PATH_MAX))
	{
		cd_error_control(cmd_path, CD_ERROR_GETCWD);
		return (0);
	}
	if (!env_change_value("PWD", ft_strdup(pwd), env_list))
		env_add_node(ft_strjoin("PWD=", pwd), env_list);
	return (1);
}

void	cd_cmd(char **cmd_argv, t_env *env_list)
{
	char	*path;
	char	*home;

	home = env_get_value_by_key("HOME", env_list);
	if (!cmd_argv[1] || cmd_argv[1][0] == '~')
	{
		if (!home)
			return (cd_error_control(cmd_argv[1], CD_ERROR_HOME_NOT_SET));
		if (!cmd_argv[1])
			path = ft_strdup(home);
		else
			path = ft_strjoin(home, cmd_argv[1] + 1);
	}
	else
		path = ft_strdup(cmd_argv[1]);
	if (chdir(path) == -1)
	{
		free(path);
		return (cd_error_control(cmd_argv[1], CD_ERROR_NO_SUCH_FILE));
	}
	free(path);
	if (!cd_cmd_set_env_pwd_oldpwd(cmd_argv[1], env_list))
		return ;
	g_exit_code = EXIT_SUCCESS;
}
