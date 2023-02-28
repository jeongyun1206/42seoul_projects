/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:32 by jnho              #+#    #+#             */
/*   Updated: 2023/02/22 15:57:40 by seonghyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "get_next_line/get_next_line.h"

/* exit codes */
# define EXECUTE_SUCCESSED 0
# define EXECUTE_FAILED 1
# define PERMISSION_DEINED 126
# define COMMAND_NOT_FOUND 127
# define SIGNAL_STOPPED 130

/* builtin cmd error_codes */
# define CD_ERROR_NO_SUCH_FILE 1
# define CD_ERROR_GETCWD 2
# define CD_ERROR_HOME_NOT_SET 3
# define EXPORT_BAD_OPTION 1
# define EXPORT_NOT_VALID 2

/* fds macros */
# define FORK_NO 0
# define FORK_OK 1
# define STDIN 0
# define STDOUT 1

int	g_exit_code;

typedef enum e_flag {
	INPUT = 0,
	HEREDOC,
	OUTPUT,
	APPEND
}	t_flag;

typedef enum e_sig {
	IGNORE = 0,
	DEFAULT,
	HANDLER
}	t_sig;

typedef enum e_quoto {
	SINGLE = 0,
	DOUBLE,
	NONE
}	t_quoto;

typedef struct s_file
{
	char			*file_name;
	int				here_flag;
	struct s_file	*next;
}	t_file;

typedef struct s_fds
{
	t_file	*input_file_list;
	int		input_file_fd;
	int		input_pipe_flag;
	t_file	*output_file_list;
	int		output_file_fd;
	int		output_pipe_flag;
}	t_fds;

typedef struct s_cmd
{
	t_fds			fds;
	char			**cmd;
	int				pipe_idx;
	int				flag;
	int				quot_flag[2];
	int				cmd_count;
	struct s_env	*env_list;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* ./main.c */

void	print_cmd(t_cmd *cmd);
void	handler(int signal);
void	set_signal(int sig_flag);
void	check(void);
void	main_init(int argc, char **argv);

/* ./built_in_cmds/cd_cmd.c */

void	cd_error_control(char *cmd_path, int error_code);
int		cd_cmd_set_env_pwd_oldpwd(char *cmd_path, t_env *env_list);
void	cd_cmd(char **cmd_argv, t_env *env_list);

/* ./built_in_cmds/echo_cmd.c */

int		echo_cmd_option(char *cmd_option);
void	echo_cmd(char **cmd_argv);

/* ./built_in_cmds/env_cmd.c */

void	env_error_control(char **cmd_argv, int option);
void	env_cmd(char **cmd_argv, t_env *env_list);

/* ./built_in_cmds/env_list.c */

void	env_add_node(char *key_value_string, t_env *env_list);
char	*env_get_value_by_key(char *key, t_env *env_list);
int		env_delete_node_by_key(char *key, t_env *env_list);
t_env	*env_char_to_list(char **env);
char	**env_list_to_char(t_env *env_list);

/* ./built_in_cmds/env_list_utils.c */

t_env	*env_new_node(char *env);
void	free_env_node(t_env *env_node);
int		env_list_len(t_env *env_list);
char	*env_get_key_in_string(char *str);
int		env_change_value(char *key, char *new_value, t_env *env_list);

/* ./built_in_cmds/exit_cmd.c */

int		exit_cmd_error_control(char *option);
int		exit_cmd_check_option_is_numuric(char *option);
int		exit_cmd_option_to_exit_code(char *option);
void	exit_cmd(char **cmd_argv);

/* ./built_in_cmds/export_cmd.c */

void	export_error_control(char *env_key_value, int option);
void	sort_env(char **env);
void	export_cmd_with_no_arguments(t_env *env_list);
int		export_cmd_key_check(char *key);
void	export_cmd(char **cmd_argv, t_env *env_list);

/* ./built_in_cmds/export_cmd_utils.c */

void	export_cmd_modify_env(char *key, char *key_value, t_env *env_list);

/* ./built_in_cmds/pwd_cmd.c */

void	pwd_error_control(char **cmd_argv, int option);
void	pwd_cmd(char **cmd_argv, t_env *env_list);

/* ./built_in_cmds/unset_cmd.c */

void	unset_error_control(char **cmd_argv, int option);
void	unset_cmd(char **cmd_argv, t_env *env_list);

/* ./execute_cmds/minishell_execute_utils.c */

void	execute_cmd_error_control(t_cmd *cmd, int exit_code);
void	free_all_vars(t_cmd *cmd, int **pipe_arr, pid_t *pid_arr);
pid_t	*set_pid_arr(size_t cmd_len);
int		**set_pipe_arr(size_t cmd_len);
void	wait_all_pid(pid_t *pid_arr, size_t cmd_len);

/* ./execute_cmds/minishell_execute_utils_2.c */

void	execute_fork_no_cmds(t_cmd *exe_cmd, t_env *env_list, int **pipe_arr);
void	exit_cmd_line(t_cmd *cmd, pid_t *pid_arr, int **pipe_arr);

/* ./execute_cmds/minishell_fds_functions.c */

void	redirect_input_file(t_fds *fds, t_env *env_list, int pipe_fd);
void	redirect_output_file(t_fds *fds, int pipe_fd);
void	redirect_fds(t_cmd *exe_cmd, t_env *env_list, int **pipe_arr, int fork);

/* ./execute_cmds/minishell_fds_utils.c */

t_file	*get_last_file(t_file *file_list);
void	free_file_list(t_file *file_list);
void	unlink_heredoc_files(t_file *input_file_list);
void	close_all_fds(t_cmd *cmd, int **pipe_arr);

/* ./execute_cmds/minishell_heredoc.c */

char	*get_heredoc_file_name(t_env *env_list);
void	write_heredoc_file(char *heredoc_file_name, char *limiter);
void	redirect_set_heredoc(t_file *input_file_list, t_env *env_list);

/* ./execute_cmds/minishell_utils.c */

void	free_argv_var(char **argv);
int		argv_len(char **argv);
size_t	lstlen(t_cmd *cmd);

/* ./execute_cmds/minshell_execute_cmd.c */

int		categorize_cmds(t_cmd *cmd);
void	execute_built_in_cmds(t_cmd *cmd, t_env *env_list);
void	set_binary_cmds(t_cmd *cmd, t_env *env_list);
void	execute_fork_cmds(t_cmd *cmd, t_cmd *e_cmd, t_env *e_list, int **p_arr);
void	execute_cmds(t_cmd *cmd, t_env *env_list);

/* ./get_next_line/get_next_line.c */

char	*gnl_free(t_gnl_vars *var1, t_gnl_vars *var2);
int		gnl_set_vars(t_gnl_vars *var, size_t len);
char	*gnl_join(char *rtn, t_gnl_vars *buff);
char	*gnl_new_line(t_gnl_vars *line, int fd);
char	*get_next_line(int fd);

/* ./get_next_line/get_next_line_utils.c */

char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);

/* ./parser/env_parse.c */

char	*env_exception(char **str);
char	*get_env(char **str, t_cmd *cmd);
char	*trans_str(char *str, t_cmd *cmd);

/* ./parser/minishell_utils.c */

t_file	*ms_lstnew(char *str, int flag);
void	ms_lstadd_back(t_file **lst, t_file *new);
t_file	*ms_lstlast(t_file *lst);
void	ms_lstclear(t_file **lst);
void	free_split(char **doc);

/* ./parser/minishell_utils2.c */

void	set_flag(t_cmd *cmd, char c);
void	get_pipetoken(t_cmd **cmd);
void	get_others(char **str, t_cmd *cmd);
int		redirect_flag(char c, int *flag0, int *flag1);

/* ./parser/parse.c */

char	**cmd_alloc(char **str, t_cmd *cmd, int count);
void	get_token(char *str, t_cmd *cmd);
t_cmd	*init_struct(int num, t_env *env_list);
void	export_cmd_key_move(char **key);

/* ./parser/syntax.c */

int		quoto_check(char *str);
int		pipe_check(char *str);
int		redirect_check(char *str);
int		syntax_check(char *str);
int		cmd_syntaxcheck(t_cmd *cmd);

/* ./parser/token.c */

void	get_endofstr(char **str, t_cmd *cmd);
char	*get_string(char **str, t_cmd *cmd);
void	list_append(char **str, t_cmd *cmd, int flag);
void	get_input(char **str, t_cmd *cmd);
void	get_output(char **str, t_cmd *cmd);

/* ./parser/string.c */

char	*strcut_str(char **str);
char	*strcut_str_double(char **str);
char	*get_quot(char **str, t_cmd *cmd);
char	*get_single(char **str);
char	*get_double(char **str, t_cmd *cmd);

#endif
