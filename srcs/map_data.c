#include "../includes/bsq.h"

//this file is for getting data of the file like chars, size, line number
int	ft_get_l_number(char *file_name)
{
	char	buf;
	int		i;
	int		fd;
	int		result;

	result = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf < '0' || buf > '9')
			break ;
		result = (result * 10) + (buf - '0');
	}
	close(fd);
	return (result);
}

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
