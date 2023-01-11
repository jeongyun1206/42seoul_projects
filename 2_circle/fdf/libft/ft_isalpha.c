/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:27 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:14:51 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if (65 <= argument && argument <= 90)
		return (1);
	else if (97 <= argument && argument <= 122)
		return (1);
	return (0);
}
