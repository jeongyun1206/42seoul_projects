/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:40:53 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 19:05:04 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rtn_lst;
	t_list	*tmp;

	if (!lst)
		return (0);
	rtn_lst = (t_list *)malloc(sizeof(t_list));
	if (!rtn_lst)
		return (0);
	rtn_lst->content = f(lst->content);
	rtn_lst->next = 0;
	while (lst->next)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
		{
			ft_lstclear(&rtn_lst, del);
			return (0);
		}
		lst = lst->next;
		tmp->content = f(lst->content);
		tmp->next = 0;
		ft_lstadd_back(&rtn_lst, tmp);
	}
	return (rtn_lst);
}
