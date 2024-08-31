#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_size_file(char *file_name);
int		ft_get_l_number(char *file_name);
char	ft_get_obstacle(char *file_name);
char	ft_get_void(char *file_name);
char	ft_get_full(char *file_name);
typedef struct s_map_data
{
	char	empty;
	char	obst;
	char	full;
	int		file_size;
	int		line;
} t_map_data;
#endif

