/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:06:08 by jnho              #+#    #+#             */
/*   Updated: 2022/12/15 17:02:18 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>

typedef struct s_gnl_vars
{
	char	*arr;
	size_t	idx;
	size_t	len;
}	t_gnl_vars;

char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
char	*gnl_free(t_gnl_vars *var1, t_gnl_vars *var2);
int		gnl_set_vars(t_gnl_vars *var, size_t len);
char	*gnl_join(char *rtn, t_gnl_vars *buff);
char	*gnl_new_line(t_gnl_vars *line, int fd);
char	*get_next_line(int fd);

#endif
