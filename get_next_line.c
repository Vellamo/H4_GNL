/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2023/01/10 15:22:52 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(void **as)
{
	if (!(*as))
		return ;
	free(*as);
	*as = 0;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)(s));
		else
			s++;
	}
	if ((char)c == '\0' && *s == '\0')
		return ((char *)(s));
	else
		return (0);
}

/*
** Overlap-safe way to add new data to the existing data.
*/

static char	*array_add(char *array, char *buffer)
{
	char	*swap;

	if (!buffer)
		return (NULL);
	if (array[0] == '\0')
		swap = ft_strdup(buffer);
	else
		swap = ft_strjoin(array, buffer);
	free(array);
	array = swap;
	return (swap);
}

/*
** line_output finds a defined EOF. Frees memory not needed.
** Returns gnl_out, or null based on parameter given.
*/

static char	*line_output(char **arr_str)
{
	unsigned int	i;
	unsigned int	len;
	char			*gnl_out;
	char			*temp;

	if (!(*arr_str))
		return (NULL);
	i = 0;
	gnl_out = NULL;
	len = ft_strlen((*arr_str));
	while ((*arr_str)[i] != '\0' && ((*arr_str)[i]) != '\n')
		i++;
	if ((*arr_str)[i] == '\n')
		i++;
	if (i != 0)
	{
		gnl_out = ft_substr((*arr_str), 0, i);
		temp = ft_substr((*arr_str), i, (len - i));
		free((*arr_str));
		*arr_str = temp;
	}
	if ((*arr_str)[0] == '\0')
		ft_strdel((void **)arr_str);
	return (gnl_out);
}

/*
** Read continues until \n is found for BUFFER_SIZE bytes
** reading into "buffer", upon which it breaks the loop.
** If the array is empty and read is finished, returns NULL
*/

char	*get_next_line(int fd)
{
	static char	*array[1024];
	char		buffer[BUFFER_SIZE + 1];
	int			read_return;

	if (!BUFFER_SIZE || BUFFER_SIZE < 1 || fd < 0 || fd > 1023)
		return (NULL);
	read_return = (read(fd, buffer, BUFFER_SIZE));
	if (read_return <= 0)
		return (NULL);
	while (read_return > 0)
	{
		buffer[read_return] = '\0';
		if (array[fd] != NULL)
			array[fd] = array_add(array[fd], buffer);
		else
			array[fd] = ft_strdup(buffer);
		if (array[fd] == NULL)
			return (NULL);
		if (ft_strchr(array[fd], '\n'))
			break ;
		read_return = (read(fd, buffer, BUFFER_SIZE));
	}
	if ((read_return <= 0) && (array[fd] == NULL))
		return (NULL);
	return (line_output(&(array[fd])));
}
