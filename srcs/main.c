#include "../includes/bsq.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	char **map =  ft_read_map(argv[1]);
	int line = ft_get_l_number(argv[1]);
	int i = 0;
	while (i < line)
	{
		printf("%s\n", map[i]);
		i++;
	}
}
