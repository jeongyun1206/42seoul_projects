/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:29:33 by jnho              #+#    #+#             */
/*   Updated: 2023/02/09 13:58:35 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_file	*node;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		if (tmp->cmd)
		{
			while (tmp->cmd[i])
			{
				printf("cmd is : %s\n", tmp->cmd[i]);
				i++;
			}
			i = 0;
		}
		printf("input_file pointer is : %p\n", tmp->fds.input_file_list);
		printf("input_pipe_flag is : %d\n", tmp->fds.input_pipe_flag);
		node = tmp->fds.input_file_list;
		while (node)
		{
			printf("input file is : %s\n", node->file_name);
			printf("input flag is : %d\n", node->here_flag);
			node = node->next;
		}
		ms_lstclear(&(cmd->fds.input_file_list));
		printf("output_file pointer is : %p\n", tmp->fds.output_file_list);
		printf("output_pipe_flag is : %d\n", tmp->fds.output_pipe_flag);
		node = tmp->fds.output_file_list;
		while (node)
		{
			printf("output file is : %s\n", node->file_name);
			printf("output flag is : %d\n", node->here_flag);
			node = node->next;
		}
		ms_lstclear(&(cmd->fds.output_file_list));
		printf("pipe_idx is : %d\n", tmp->pipe_idx);
		tmp = tmp->next;
	}
}

void	handler(int signal)
{
	printf("minishell-1.0$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	signal = 0;
}

void	check(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **env)
{
	t_cmd			*cmd;
    t_env           *env_list;
	char			*str;
	struct termios	term;

    argc = 0;
    argv = 0;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	//atexit(check);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
    env_list = env_char_to_list(env);
	while (1)
	{
		str = readline("minishell-1.0$ ");
		cmd = init_struct(0);
		if (str)
		{
			get_token(str, cmd);
			// print_cmd(cmd);
		}
		else if (str == NULL)
		{
			write(1, "exit\n", 5);
			exit (0);
		}
		add_history(str);
		free(str);
        //print_cmd(cmd);
        execute_cmds(cmd, env_list);
	}
	exit(0);
}