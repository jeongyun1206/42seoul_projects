/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:57:52 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 19:06:14 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
	tmp = *lst;
	del((tmp)->content);
	free(tmp);
	*lst = 0;
}
