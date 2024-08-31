#include "../includes/bsq.h"

char	ft_get_obstacle(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	close(fd);
	return (buf[i - 2]);
}

char	ft_get_void(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	close(fd);
	return (buf[i - 3]);
}

char	ft_get_full(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	close(fd);
	return (buf[i - 1]);
}
