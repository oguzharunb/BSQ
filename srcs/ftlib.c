#include "../includes/bsq.h"

int	ft_size_file(char *file_name)
{
	int		size;
	char	buf;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

int	ft_cursor_to_next_line(int fd)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc(4096 * sizeof(char));
	if (buf == NULL)
		return ;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
		{
			free(buf);
			break ;
		}
		i++;
	}
	return (i);
}
