/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:45 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 19:23:02 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*begin;

	if (!lst)
		return (0);
	begin = lst;
	size = 1;
	while (begin->next)
	{
		begin = begin->next;
		size++;
	}
	return (size);
}
