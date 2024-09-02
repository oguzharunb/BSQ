#include "../includes/bsq.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	if(argc < 1)
		return 1;
	write(1, "zero", 4);
	char **map = ft_read_map(argv[1]);
	write(1, "one", 3);
	int **matrix = ft_find_solution(map, 3, 3, 'o');
	write(1, "two", 3);
	t_bsq bsq = ft_find_bsq_in_matrix(matrix, 3, 3);
	printf("%i, %i, %i", bsq.size, bsq.x, bsq.y);
}