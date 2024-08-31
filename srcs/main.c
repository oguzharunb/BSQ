#include "../includes/bsq.h"
#include <stdio.h>

int	ft_get_l_number(char *file_name)
{
	char	*buf;
	int		i;
	int		fd;
	int		result;

	buf = malloc(sizeof(char) * 80);
	result = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] < '0' || buf[i] > '9')
			break ;
		result = (result * 10) + (buf[i] - '0');
		i++;
	}
	free(buf);
	close(fd);
	return (result);
}

int	main(void)
{
	printf("%d", ft_get_l_number("mapfalse"));
	return (0);
}
