/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:32:40 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 19:16:39 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	begin = *lst;
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}
