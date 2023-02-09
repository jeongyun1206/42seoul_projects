/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:26 by jnho              #+#    #+#             */
/*   Updated: 2023/02/09 14:03:11 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    cd_error_control(char *path, int error_code)
{
    if (error_code == CD_ERROR_NO_SUCH_FILE)
    {
        write(2, "cd: ", 3);
        write(2, path, ft_strlen(path));
        write(2, ": No such file or directory\n", 28);
    }
    else if (error_code == CD_ERROR_GETCWD)
    {
        write(2, "cd: error retrieving current directory: ", 30);
        write(2, "getcwd: cannot access parent directories: ", 41);
        write(2, "No such file or directory\n", 26);
    }
    else if (error_code == CD_ERROR_HOME_NOT_SET)
    {
        write(2, "cd: HOME not set\n", 17);
    }
}

int cd_cmd_move_to_home(char *path, t_env *env_list)
{
    char *to_move_path;

    to_move_path = env_get_value_by_key("HOME", env_list);
    if (!to_move_path)
    {
        cd_error_control(path, CD_ERROR_HOME_NOT_SET);
        return (0);
    }
    if (chdir(to_move_path) == -1)
    {
        cd_error_control(to_move_path, CD_ERROR_NO_SUCH_FILE);
        return (0);
    }
    return (1);
}

int cd_cmd_move_to_home_path(char *path, t_env *env_list)
{
    char *to_move_path;

    to_move_path = env_get_value_by_key("HOME", env_list);
    if (!to_move_path)
    {
        cd_error_control(path, CD_ERROR_HOME_NOT_SET);
        return (0);
    }
    to_move_path = ft_strjoin(to_move_path, path + 1);
    if (chdir(to_move_path) == -1)
    {
        cd_error_control(to_move_path, CD_ERROR_NO_SUCH_FILE);
        free(to_move_path);
        return (0);
    }
    free(to_move_path);
    return (1);
}

int cd_cmd_move_to_relative_path(char *path, char *old_pwd)
{
    char    *to_move_path;
    char    *to_move_path_buf;

    to_move_path_buf = ft_strjoin(old_pwd, "/");
    to_move_path = ft_strjoin(to_move_path_buf, path);
    free(to_move_path_buf);
    if (chdir(to_move_path) == -1)
    {
        cd_error_control(path, CD_ERROR_NO_SUCH_FILE);
        free(to_move_path);
        return (0);
    }
    free(to_move_path);
    return (1);
}

void    cd_cmd(char **cmd_argv, t_env *env_list)
{
    char    *path;
    char    old_pwd[PATH_MAX];
    char    pwd[PATH_MAX];

    path = cmd_argv[1];
    if (!getcwd(old_pwd, PATH_MAX))
        return (cd_error_control(path, CD_ERROR_GETCWD));
    if (!path && !cd_cmd_move_to_home(path, env_list))
        return;
    else if (path && path[0] == '/' && chdir(path) == -1)
        return (cd_error_control(path, CD_ERROR_NO_SUCH_FILE));
    else if (path && path[0] == '~' && !cd_cmd_move_to_home_path(path, env_list))
        return ;
    else if (path && path[0] != '/' && path[0] != '~' && !cd_cmd_move_to_relative_path(path, old_pwd))
        return ;
    if (!getcwd(pwd, PATH_MAX))
        return (cd_error_control(path, CD_ERROR_GETCWD));
    if (!env_change_value("OLD_PWD", ft_strdup(old_pwd), env_list)) // leak check
        env_add_node(ft_strjoin("OLD_PWD=", old_pwd), env_list);
    if (!env_change_value("PWD", ft_strdup(pwd), env_list))
        env_add_node(ft_strjoin("PWD=", pwd), env_list);
}
/*
int main(int argc, char **argv, char **env)
{
    t_env *env_list = env_char_to_list(env);
    argc = 0;
    cd_cmd(argv, env_list);
    ft_printf("PWD = %s\n", env_get_value_by_key("PWD", env_list));
    ft_printf("OLD_PWD = %s\n", env_get_value_by_key("OLD_PWD", env_list));
}*/