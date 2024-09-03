#include "../includes/bsq.h"

//This function will give us size of file.
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

//this file is for getting data of the file like chars, size, line number
int	ft_get_l_number(char *file_name)
{
	char	buf;
	int		i;
	int		fd;
	int		result;

	result = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf < '0' || buf > '9')
			break ;
		result = (result * 10) + (buf - '0');
		i++;
	}
	close(fd);
	return (result);
}

int	ft_get_c_number(char *file_name)
{
	char	*buf;
	int		j;
	int		size_file;
	int		fd;

	j = 0;
	fd = open(file_name, O_RDONLY);
	size_file = ft_size_file(file_name);
	ft_cursor_to_next_line(fd);
	buf = malloc(size_file * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free (buf);
	close(fd);
	return (j + 1);
}

char	**ft_create_map(int row, int col)
{
	int		i;
	char	**buff;

	buff = malloc(row * sizeof(char *));
	if (!buff)
		return (NULL);
	i = 0;
	while (i < row)
	{
		buff[i] = malloc(col * sizeof(char));
		if (!buff[i])
			return (NULL);
		i++;
	}
	return (buff);
}

char	**ft_read_map(char *file_name)
{
	char	**buff;
	int		i;
	int		file;
	int		col;
	int		row;

	i = 0;
	row = ft_get_l_number(file_name);
	col = ft_get_c_number(file_name);
	file = open(file_name, O_RDONLY);
	ft_cursor_to_next_line(file);
	buff = ft_create_map(row, col);
	while (i < row)
	{
		if (read(file, buff[i], col) == -1)
			return (NULL);
		buff[i][col - 1] = '\0';
		i++;
	}
	close (file);
	return (buff);
}
