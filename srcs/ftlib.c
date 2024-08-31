#include "../includes/bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

int	ft_size_file(char *file_name)
{
    int size;
    char buf;
    int fd;

    size = 0;
    fd = open(file_name, O_RDONLY);
    while (read(fd, &buf, 1))
        size++;
    close(fd);
    return (size);
}
