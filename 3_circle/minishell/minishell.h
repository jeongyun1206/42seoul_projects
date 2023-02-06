/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:32 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 18:29:15 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_fds
{
    int             input_file_fd;
    char            *input_file_name;
    int             here_doc_flag;
    char            *limiter;
    int             input_pipe_flag;

    int             output_file_fd;
    char            *output_file_name;
    int             file_append_flag;
    int             output_pipe_flag;
}   t_fds;

typedef struct s_cmd
{
    t_fds           fds;
    char            **cmd;
    int             pipe_idx;
	int				quot_flag[2];
    struct s_cmd    *next;
}   t_cmd;

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

/* utils */
void    free_argv_var(char **argv);
int     argv_len(char **argv);
size_t  lstlen(t_cmd *cmd);
/* env */
t_env   *env_new_node(char *env);
void    free_env_node(t_env *env_node);
int     env_list_len(t_env *env_list);
void    env_add_node(char *key_value_string, t_env *env_list);
char    *env_get_key_in_string(char *str);
char    *env_get_value_by_key(char *key, t_env *env_list);
int     env_delete_node_by_key(char *key, t_env *env_list);
t_env   *env_char_to_list(char **env);
char    **env_list_to_char(t_env *env_list);
/* built in cmds */
void    env_cmd(char **cmd_argv, t_env *env_list);
void    echo_cmd(char **cmd_argv);
void    cd_cmd(char **cmd_argv, t_env *env_list);
void    exit_cmd(void);
void    export_cmd(char **cmd_argv, t_env *env_list);
void    pwd_cmd(char **cmd_argv);
void    unset_cmd(char **cmd_argv, t_env *env_list);
/* fds */
void    redirect_fds(t_cmd *cmd, t_env *env_list, int **pipe);
void    close_all_fds(t_cmd *cmd, int **pipe);

void    free_all_vars(t_cmd *cmd, int **pipe, pid_t *pid_arr);
pid_t   *set_pid_arr(size_t cmd_len);
int     **set_pipe_arr(size_t cmd_len);
void    wait_all_pid(pid_t *pid_arr, size_t cmd_len);

/* execute */
void    execute_cmds(t_cmd *cmd, t_env *env_list);

/* parse.c */
void	get_token(char *str, t_cmd *cmd);
t_cmd	*init_struct(int num);
/* token.c */
char	*get_string(char **str, t_cmd *cmd, int flag);
void	get_input(char **str, t_cmd *cmd);
void	get_output(char **str, t_cmd *cmd);
void	set_flag(t_cmd *cmd, char c);
/* uils.c */

// parser