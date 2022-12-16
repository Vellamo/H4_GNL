/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2022/12/02 16:35:58 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}

void	ft_strdel(void **as)
{
	if (!*as)
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

static void	buffer_add(char *buffer, char *array)
{
	char		*swap;

	swap = ft_strjoin(array, buffer);
	free(array);
	array = swap;
}

/*
** line_output finds a defined EOF. Frees memory not needed.
** Returns value based on **line output for GNL.c to use.
*/

static char	*line_output(char *string, char *line)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while ((string[i]) != '\0' && (string[i]) != '\n')
		i++;
	if ((string[i]) == '\n')
	{
		line = ft_substr(string, 0, i);
		temp = ft_strdup(&(string[i + 1]));
		ft_strdel(string);
		string = temp;
		if ((string[0]) == '\0')
			ft_strdel(string);
	}
	else
	{
		line = ft_strdup(string);
		ft_strdel(string);
	}
	return (line);
}

/*
** Read continues until \n is found, upon which it breaks the loop.
** If the array is empty and read is finished, returns NULL
*/

char	*get_next_line(int fd)
{
	static char	*array[2048];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_return;

	read_return = 1;
	line = 0;
	ft_bzero(array, 2048);
	if (!BUFFER_SIZE)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while ((read_return = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		buffer[read_return] = '\0';
		if (array[fd] == NULL)
		{
			array[fd] = ft_strdup(buffer);
			if (!(array[fd]))
				return (NULL);
		}
		else
			buffer_add((char *)buffer, array[fd]);
		if (ft_strchr(array[fd], '\n'))
			break ;
	}
	if ((read_return == 0) && (array[fd] == NULL))
		return (NULL);
	if (read_return != -1)
		return (line_output(array[fd], line));
	return (NULL);
}
