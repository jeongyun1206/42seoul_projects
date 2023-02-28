/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:05:27 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 13:05:04 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_cmd_option(char *cmd_option)
{
	int	option_idx;

	if (cmd_option[0] != '-')
		return (0);
	option_idx = 1;
	while (cmd_option[option_idx])
	{
		if (cmd_option[option_idx] != 'n')
			return (0);
		option_idx++;
	}
	return (1);
}

void	echo_cmd(char **cmd_argv)
{
	int	option;
	int	cmd_idx;

	cmd_idx = 1;
	while (cmd_argv[cmd_idx])
	{
		if (echo_cmd_option(cmd_argv[cmd_idx]))
			option = 0;
		else
			break ;
		cmd_idx++;
	}
	while (cmd_argv[cmd_idx])
	{
		write(1, cmd_argv[cmd_idx], ft_strlen(cmd_argv[cmd_idx]));
		if (cmd_argv[cmd_idx + 1])
			write(1, " ", 1);
		cmd_idx++;
	}
	if (option)
		write(1, "\n", 1);
	exit(EXECUTE_SUCCESSED);
}
