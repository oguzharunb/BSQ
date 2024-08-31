#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>

char	ft_get_l_number(char *file_name);
typedef struct s_map_data
{
	char	emty;
	char	obst;
	char	sqrx;
	int		n_line;
} t_map_data;
#endif

