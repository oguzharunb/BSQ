#include "../includes/bsq.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	int i = 1;
	int ret = 0;
	while (i < argc)
	{
		ret = ft_verify_columns(argv[1]);
		printf("%i", ft_get_c_number(argv[1]));
		i++;
	}
	return (ret);
}
