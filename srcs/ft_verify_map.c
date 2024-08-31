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
		return (NULL);
	ret = read(fd, buf, map_data.file_size);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] != map_data.empty && buf[i]
			!= map_data.obst && buf[i] != '\n')
			return (1);
	}
	close(fd);
	free(buf);
	return (0);
}

//this function checks if number of columns fits
int	ft_get_next_columns(int fd)
{
	char	*buf;
	int		j;
	int		size_file;

	j = 0;
	buf = malloc((4096) * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free (buf);
	return (j + 1);
}

int         ft_verif_columns(char *argv)
{
    int i;
    int fd;
    int j;
    int c;
    int l;

    i = 0;
    j = 0;
    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);
    fd = open(argv, O_RDONLY);
    ft_get_second_line(fd);
    while (i < l)
    {
        j = ft_get_next_columns(fd);
        if (j != c)
            return (1);
        i++;
    }
    close(fd);
    return (0);
}