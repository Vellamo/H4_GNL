# H4_GNL

get_next_line is a C function that reads text from a file descriptor (fd) one line at a time, using a specified buffer size (BUFFER_SIZE). The function can be used on any type of file and will return a line of text, or NULL if there are no more lines to be read.

The function uses static arrays to store data between calls and memory is managed efficiently with ft_strdel and ft_strjoin. The function also includes the utility function ft_strchr, which finds a defined end-of-file (EOF) in the text.

## Usage

To use get_next_line, simply pass a valid file descriptor to the function. The buffer size can be adjusted by changing the value of BUFFER_SIZE.
```
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
```
## Contributions

This function was created by lharvey.
