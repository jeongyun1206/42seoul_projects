/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:13:07 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 14:06:37 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_cmd_error_control(char *option)
{
	write(2, "bash: exit: ", 12);
	write(2, option, ft_strlen(option));
	write(2, ": numeric argument required\n", 28);
	return (255);
}

int	exit_cmd_check_option_is_numuric(char *option)
{
	int	idx;

	idx = 0;
	while (option[idx])
	{
		if (idx == 0 && option[idx] == '-')
		{
			idx++;
			continue ;
		}
		if (option[idx] < '0' || '9' < option[idx])
			return (exit_cmd_error_control(option));
		idx++;
	}
	if ((ft_strncmp("0", option, 2) && ft_atoi(option) == 0)
		|| (ft_strncmp("-1", option, 3) && ft_atoi(option) == -1))
		return (exit_cmd_error_control(option));
	return (0);
}

int	exit_cmd_option_to_exit_code(char *option)
{
	unsigned char	exit_code;

	exit_code = (unsigned char)ft_atoi(option);
	return ((int)exit_code);
}

void	exit_cmd(char **cmd_argv)
{
	int	exit_code;

	if (argv_len(cmd_argv) >= 3)
	{
		write(2, "bash: exit: too many arguments\n", 32);
		g_exit_code = 1;
		return ;
	}
	exit_code = 0;
	if (argv_len(cmd_argv) == 2)
		exit_code = exit_cmd_check_option_is_numuric(cmd_argv[1]);
	if (argv_len(cmd_argv) == 2 && !exit_code)
		exit_code = exit_cmd_option_to_exit_code(cmd_argv[1]);
	if (!exit_code)
		write(2, "exit\n", 5);
	exit(exit_code);
}
