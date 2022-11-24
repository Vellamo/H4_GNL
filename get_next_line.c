/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2022/11/24 14:45:28 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Read continues until \n is found, upon which it breaks the loop.
** If the array is empty and read is finished, returns 0
*/

char	*get_next_line(int fd)
{
	static char	*array[fd];
	char		buffer[BUFFER_SIZE + 1];
	int			read_return;

	read_return = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((read_return = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		buffer[read_return] = '\0';
		if (array[fd] == NULL)
		{
			if (!(array[fd] = ft_strdup(buffer)))
				return (-1);
		}
		else
			buffer_add(buffer, &(array[fd]));
		if (ft_strchr(array[fd], '\n'))
			break ;
	}
	if ((read_return == 0) && (array[fd] == NULL))
		return (0);
	if (read_return != -1)
		read_return = line_output(&(array[fd]), line);
	return (read_return);
}
