/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:41:05 by seonghyu          #+#    #+#             */
/*   Updated: 2023/02/08 17:34:24 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*ms_lstnew(char *str, int flag)
{
	t_file	*re;

	re = (t_file *)malloc(sizeof(t_file));
	if (!re)
		return (NULL);
	re->file_name = str;
	re->here_flag = flag;
	re->next = NULL;
	return (re);
}

void	ms_lstadd_back(t_file **lst, t_file *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ms_lstlast(*lst)->next = new;
}

t_file	*ms_lstlast(t_file *lst)
{
	t_file	*re;
	t_file	*tmp;

	re = lst;
	if (!re)
		return (re);
	while (re)
	{
		tmp = re;
		re = re->next;
	}
	return (tmp);
}

void	ms_lstclear(t_file **lst)
{
	t_file	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp->next;
		free(tmp->file_name);
		free(tmp);
		tmp = *lst;
	}
}

void	free_split(char **doc)
{
	int	i;

	i = 0;
	while (doc[i])
	{
		free(doc[i]);
		i++;
	}
	free(doc);
}