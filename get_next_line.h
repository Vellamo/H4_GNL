/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:00:18 by lharvey           #+#    #+#             */
/*   Updated: 2023/02/15 11:49:58 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include	<unistd.h>
# include	<stdlib.h>

void			ft_strdel(void **as);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strdup(const char *s1);
unsigned int	ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);

#endif