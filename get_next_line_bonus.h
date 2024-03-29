/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:00:18 by lharvey           #+#    #+#             */
/*   Updated: 2023/02/27 11:04:28 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include	<unistd.h>
# include	<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void			ft_strdel(void **as);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strdup(const char *s1);
unsigned int	ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);

#endif