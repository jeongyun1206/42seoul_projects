/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:55:04 by jnho              #+#    #+#             */
/*   Updated: 2022/12/22 15:55:45 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../error_control/error_control.h"

static int	check_range(long long rtn_num, int next_num)
{
	long long	l_max;
	long long	l_min;

	l_max = 2147483647;
	l_min = -2147483648;
	if (rtn_num > l_max / 10)
		error_control();
	if (rtn_num < l_min / 10)
		error_control();
	if (rtn_num * 10 > l_max - next_num)
		error_control();
	if (rtn_num * 10 < l_min + next_num)
		error_control();
	return (1);
}

int	ft_atoi(const char	*str)
{
	size_t		idx;
	long long	rtn_num;
	int			sign;

	idx = 0;
	rtn_num = 0;
	sign = 1;
	while (str[idx] == ' ' || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	if (str[idx] == '+' && sign != -1)
		idx++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		if (check_range(rtn_num, str[idx] - '0') != 1)
			return (check_range(rtn_num, str[idx] - '0'));
		rtn_num *= 10;
		rtn_num += sign * (str[idx] - '0');
		idx++;
	}
	return ((int)rtn_num);
}
