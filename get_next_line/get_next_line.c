/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:43:47 by jnho              #+#    #+#             */
/*   Updated: 2022/11/30 19:28:18 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*gnl_free(t_gnl_vars *var1, t_gnl_vars *var2)
{
	if (var1)
	{
		if (var1->arr)
		{
			free(var1->arr);
			var1->arr = 0;
		}
		var1->idx = 0;
		var1->len = 0;
	}
	if (var2)
	{
		if (var2->arr)
		{
			free(var2->arr);
			var2->arr = 0;
		}
		var2->idx = 0;
		var2->len = 0;
	}
	return (0);
}

int	gnl_set_vars(t_gnl_vars *var, size_t len)
{
	if (len == SIZE_MAX)
		return (0);
	var->len = len;
	var->idx = 0;
	while (var->idx < var->len)
	{
		if ((var->arr)[var->idx] == '\n')
			break ;
		(var->idx)++;
	}
	return (1);
}

char	*gnl_join(char *rtn, t_gnl_vars *buff)
{
	char	*join;
	size_t	join_idx;
	size_t	idx;

	join = malloc(ft_strlen(rtn) + buff->len + 1);
	if (!join)
	{
		free(rtn);
		return (0);
	}
	join_idx = 0;
	idx = 0;
	if (rtn)
	{
		while (rtn[idx])
			join[join_idx++] = rtn[idx++];
	}
	idx = 0;
	while (idx < buff->len)
		join[join_idx++] = (buff->arr)[idx++];
	join[join_idx] = 0;
	free(rtn);
	return (join);
}

char	*gnl_new_line(t_gnl_vars *line, int fd)
{
	t_gnl_vars	buff;
	char		*rtn;

	rtn = 0;
	if (line->arr)
	{
		rtn = gnl_join(rtn, line);
		if (!rtn)
			return (0);
	}
	buff.arr = (char *)malloc(BUFFER_SIZE);
	if (!buff.arr)
		return (0);
	while (1)
	{
		if (!gnl_set_vars(&buff, read(fd, buff.arr, BUFFER_SIZE)))
			return (gnl_free(&buff, 0));
		rtn = gnl_join(rtn, &buff);
		if (!rtn)
			return (gnl_free(&buff, 0));
		if (buff.len == 0 || buff.len != buff.idx)
			break ;
	}
	gnl_free(&buff, line);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char				*tmp;
	char				*rtn_line;
	static t_gnl_vars	line;

	if (read(fd, 0, 0) == -1 || fd < 0)
		return (gnl_free(&line, 0));
	line.arr = gnl_new_line(&line, fd);
	if (!line.arr)
		return (gnl_free(&line, 0));
	gnl_set_vars(&line, ft_strlen(line.arr));
	rtn_line = ft_substr(line.arr, 0, line.idx + 1);
	if (!rtn_line)
		return (gnl_free(&line, 0));
	tmp = ft_substr(line.arr, line.idx + 1, line.len - line.idx);
	gnl_free(&line, 0);
	line.arr = tmp;
	gnl_set_vars(&line, ft_strlen(line.arr));
	return (rtn_line);
}
