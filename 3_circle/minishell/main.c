/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:29:33 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 18:48:07 by seonghyu         ###   ########.fr       */
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
		printf("cmd pointer is : %p\n", tmp->cmd);
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
			printf("input_heredoc flag is : %d\n", node->here_flag);
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
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal(int sig_flag)
{
	if (sig_flag == IGNORE)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig_flag == DEFAULT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	if (sig_flag == HANDLER)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
}

void	check(void)
{
	system("leaks minishell");
}

void	main_init(int argc, char **argv)
{
	struct termios	term;

	if (argc != 1)
		write(2, "Invalid Argument\n", 17);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	(void)argc;
	(void)argv;
}

int	main(int argc, char **argv, char **env)
{
	t_cmd			*cmd;
	t_env			*env_list;
	char			*str;

	main_init(argc, argv);
	//atexit(check);
	env_list = env_char_to_list(env);
	while (1)
	{
		set_signal(HANDLER);
		str = readline("minishell-1.0$ ");
		if (str == NULL)
		{
			write(1, "exit\n", 5);
			exit (0);
		}
		if (syntax_check(str) != 0)
		{
			free(str);
			continue ;
		}
		cmd = init_struct(0, env_list);
		if (str)
		{
			if (str[0])
				add_history(str);
			get_token(str, cmd);
		}
		if (cmd_syntaxcheck(cmd) != 0)
			continue ;
		free(str);
		// print_cmd(cmd);
		execute_cmds(cmd, env_list);
	}
	exit(0);
}
