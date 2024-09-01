#include "../includes/bsq.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	int i = 1;
	int ret = 0;
	while (i < argc)
	{
		printf("%i\n", ft_get_c_number(argv[i]));
		ret = ft_verify_returns(argv[i]);
		printf("%i\n", ret);
		i++;
	}
	return (ret);
}
