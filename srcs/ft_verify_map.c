/*
-> new line check
	does line_number data and number of lines in file match?
	is the map rectengular
-> char check
-> are there any other characters on the map rather than the 
ones the referred at first
-> does a map exists?

karakter sayısı // i
new line sayacı // baştakine eşit değilse map error
satırdaki karakter sayacı // biri öncekine eşit değilse map error
*/

//this file exists because we want to deal with a valid map.
#include "../includes/bsq.h"

//this function checks if there is another 
//character in map rather than expected ones
int	ft_verify_chars(char *file_name)
{
	t_map_data	map_data;
	int			fd;
	char		*buf;
	int			ret;
	int			i;

	map_data.file_size = ft_size_file(file_name);
	map_data.empty = ft_get_void(file_name);
	map_data.obst = ft_get_obstacle(file_name);
	fd = open(file_name, O_RDONLY);
	ft_cursor_to_next_line(fd);
	buf = malloc(sizeof(char) * (map_data.file_size));
	if (!buf)
		return (ERR_MEMORY);
	ret = read(fd, buf, map_data.file_size);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] != map_data.empty && buf[i]
			!= map_data.obst && buf[i] != '\n')
			return (ERR_MAP);
	}
	close(fd);
	free(buf);
	return (SUCCESS);
}

int	ft_verify_columns(char *argv)
{
	int	i;
	int	fd;
	int	j;
	int	col;
	int	line;

	i = 0;
	j = 0;
	col = ft_get_l_number(argv);
	line = ft_get_c_number(argv);
	fd = open(argv, O_RDONLY);
	ft_cursor_to_next_line(fd);
	while (i < line)
	{
		j = ft_get_next_columns(fd);
		if (j != col)
			return (ERR_MAP);
		i++;
	}
	close(fd);
	return (SUCCESS);
}

int         ft_verify_returns(char *argv)
{
    char *buf;
    int i;
    int fd;
    int size_file;
    int ret;
    int c;

    i = 0;
    ret = 0;
    c = ft_get_c_number(argv);
    size_file = ft_size_file(argv);
    fd = open(argv, O_RDONLY);
    ft_cursor_to_next_line(fd);
    if ((buf = malloc(size_file * sizeof(char))) == NULL)
        return (0);
    while ((ret = read(fd, buf, c)))
    {
        if (buf[ret - 1] != '\n')
            return (1);
    }
    free(buf);
    close(fd);
    return (0);
}

/*int	ft_verify_first_line(char *file_name)
{
	char	*buf;
	int		fd;
	int		i;

	buf = malloc(4096 * sizeof(char));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (read(fd, buf + i, 1))
	{

	}
}*/

int	ft_verify_map(char *argv)
{
	if (ft_get_c_number(argv) < 1)
	{
		ft_putstr("map error\n");
		return (ERR_COL_N);
	}
	else if (ft_get_l_number(argv) < 1)
	{
		ft_putstr("map error\n");
		return (ERR_LINE_N);
	}
	else if (ft_verify_chars(argv))
	{
		ft_putstr("map error\n");
		return (ERR_CHARS);
	}
	else if (ft_verify_returns(argv))
	{
		ft_putstr("map error\n");
		return (ERR_RET);
	}
	else if (ft_verify_columns(argv))
	{
		ft_putstr("map error\n");
		return (ERR_COL);
	}
	return (0);
}
