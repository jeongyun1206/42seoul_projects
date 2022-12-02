/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:06:08 by jnho              #+#    #+#             */
/*   Updated: 2022/11/30 20:56:10 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FD_MAX 10240
# include <stdlib.h>

typedef struct s_gnl_vars
{
	char	*arr;
	size_t	idx;
	size_t	len;
}	t_gnl_vars;

void	*ft_memcpy(void *dest, const void *src, size_t num);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*gnl_free(t_gnl_vars *var1, t_gnl_vars *var2);
int		gnl_set_vars(t_gnl_vars *var, size_t len);
char	*gnl_join(char *rtn, t_gnl_vars *buff);
char	*gnl_new_line(t_gnl_vars *line, int fd);
char	*get_next_line(int fd);

#endif
