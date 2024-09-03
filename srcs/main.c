#include "../includes/bsq.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	if(argc < 1)
		return 1;
	char **map = ft_read_map(argv[1]);
	t_us l = ft_get_l_number(argv[1]);
	write(1, "one",3);
	t_us c = ft_get_c_number(argv[1]);
	write(1, "two",3);
	t_us **matrix = ft_solve(map, l, c, 'o');
	write(1, "three",5);
	t_bsq bsq = ft_find_bsq_in_matrix(matrix, l, c);
	write(1, "four",4);
	printf("size :%d, x: %d, y: %d", bsq.size, bsq.x, bsq.y);
}

/*		char *buf = malloc(4096);
	int fd;
	int asd;
	fd = open("newmap", O_APPEND);
	while (1)
	{
		asd = read(STDIN_FILENO, buf, 4096);
		if (asd == -1)
			return (1);
	}
	write(fd, buf, asd);
	*/