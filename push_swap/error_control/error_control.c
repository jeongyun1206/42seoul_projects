/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:48:18 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 16:03:50 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_control.h"
#include <unistd.h>
#include <stdlib.h>

void	error_control(void)
{
	write(2, "error\n", 6);
	exit(1);
}
