/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:35:33 by jnho              #+#    #+#             */
/*   Updated: 2023/02/06 17:51:37 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    free_argv_var(char **argv)
{
    int idx;

    idx = 0;
    while (argv[idx])
    {
        free(argv[idx]);
        idx++;
    }
    free(argv);
}

int argv_len(char **argv)
{
    int idx;

    idx = 0;
    while (argv[idx])
        idx++;
    return (idx);
}

size_t  lstlen(t_cmd *cmd)
{
    size_t  len;
    t_cmd   *cur_cmd;

    cur_cmd = cmd;
    len = 0;
    while (cur_cmd)
    {
        len++;
        cur_cmd = cur_cmd->next;
    }
    return (len);
}
