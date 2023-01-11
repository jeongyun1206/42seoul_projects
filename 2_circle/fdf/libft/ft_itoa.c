/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:39:13 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:14:34 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_itoa(int n)
{
	int	str_cnt;

	str_cnt = 0;
	if (!n)
		return (1);
	if (n < 0)
		str_cnt++;
	while (n)
	{
		n /= 10;
		str_cnt++;
	}
	return (str_cnt);
}

char	*ft_itoa(int n)
{
	char	*rtn_arr;
	int		str_cnt;
	int		idx;

	str_cnt = cnt_itoa(n);
	rtn_arr = (char *)malloc(str_cnt + 1);
	if (!rtn_arr)
		return (0);
	idx = 1;
	if (n < 0)
	{
		idx++;
		rtn_arr[0] = '-';
	}
	rtn_arr[str_cnt] = '\0';
	while (idx <= str_cnt)
	{
		if (n < 0)
			rtn_arr[str_cnt - idx + 1] = -1 * (n % 10) + '0';
		else
			rtn_arr[str_cnt - idx] = n % 10 + '0';
		n /= 10;
		idx++;
	}
	return (rtn_arr);
}
