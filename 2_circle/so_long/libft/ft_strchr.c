/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:30:45 by jnho              #+#    #+#             */
/*   Updated: 2022/11/17 19:51:48 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *str, int ch)
{
	size_t	idx;

	idx = 0;
	while (str[idx] && (unsigned char)str[idx] != (unsigned char)ch)
		idx++;
	if (str[idx] == '\0' && (unsigned char)ch != '\0')
		return (0);
	return ((char *)str + idx);
}
