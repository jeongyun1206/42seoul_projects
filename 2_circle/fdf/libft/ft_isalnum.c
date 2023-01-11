/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:56 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:14:45 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if (48 <= argument && argument <= 57)
		return (1);
	else if (65 <= argument && argument <= 90)
		return (1);
	else if (97 <= argument && argument <= 122)
		return (1);
	return (0);
}
