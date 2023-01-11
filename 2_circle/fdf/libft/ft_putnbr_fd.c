/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:38:35 by jnho              #+#    #+#             */
/*   Updated: 2022/11/15 14:56:01 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_prt_int(char *num_arr, int nb, int fd)
{
	int	idx;

	idx = 0;
	while (nb)
	{
		num_arr[idx] = nb % 10 + '0';
		nb /= 10;
		idx ++;
	}
	while (idx)
	{
		idx--;
		write(fd, num_arr + idx, 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	num_arr[10];

	if (nb <= -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	ft_prt_int(num_arr, nb, fd);
}
