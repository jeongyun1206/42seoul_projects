/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:26 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 14:15:30 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    cd_error_control(char *path, int error_option)
{
    char    *error_message;

    if (error_option == 1)
    {
        error_message = ft_strjoin("cd: no such file or directory: ", path);
        write(2, error_message, ft_strlen(error_message));
        write(2, "\n", 1);
        free(error_message);
    }
    else if (error_option == 3)
    {
        write(2, "cd: string not in pwd: ", 23);
        write(2, path, ft_strlen(path));
        write(2, "\n", 1);
    }
    else
        write(2, "cd: too many arguments\n", 23);
}

void    cd_cmd_absolute_path(char *path)
{
    if (chdir(path) == -1)
        cd_error_control(path, 1);
    return;
}

void    cd_cmd_relative_path(char *path)
{
    char    current_path[PATH_MAX];
    char    *cd_path_buf;
    char    *cd_path;

    if (!getcwd(current_path, PATH_MAX))
    {
        cd_error_control(path, 1);
        return;
    }
    cd_path_buf = ft_strjoin(current_path, "/");
    cd_path = ft_strjoin(cd_path_buf, path);
    if (chdir(cd_path) == -1)
        cd_error_control(path, 1);
    free(cd_path_buf);
    free(cd_path);
}
// env에 OLD_PWD, PWD바뀜.
void    cd_cmd(char **cmd_argv, t_env *env_list)
{
    char    *path;

    path = cmd_argv[1];
    if (argv_len(cmd_argv) == 1)
        cd_cmd_absolute_path(env_get_value_by_key("HOME", env_list));
    else if (argv_len(cmd_argv) == 2)
    {
        if (path[0] == '/')
            cd_cmd_absolute_path(path);
        else if (path[0] == '~')
        {
            cd_cmd_absolute_path(env_get_value_by_key("HOME", env_list));
            cd_cmd_relative_path(path + 2);
        }
        else
            cd_cmd_relative_path(path);
    }
    else if (argv_len(cmd_argv) == 3)
        cd_error_control(path, 3);
    else
        cd_error_control(path, 4);
}