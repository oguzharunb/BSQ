#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define SUCCESS 0
# define ERR_MAP 1
# define ERR_MEMORY 2
# define ERR_COL 4
# define ERR_LINE 8
# define ERR_RET 16
# define ERR_CHARS 32
# define ERR_COL_N 64
# define ERR_LINE_N 128
# define ERR_NO_FILE 256
# define ERR_READ 512

typedef struct s_map_data
{
	char	empty;
	char	obst;
	char	full;
	int		file_size;
	int		line;
}	t_map_data;

typedef struct s_bsq
{
	int	size;
	int	x;
	int	y;
}	t_bsq;
int		ft_strlen(char *str);
int		ft_get_to_next_l(int fd);
void	ft_cursor_to_next_line(int fd);
int		ft_get_next_columns(int fd);
void	ft_putstr(char *str);
int		ft_size_file(char *file_name);
int		ft_get_l_number(char *file_name);
int		ft_get_c_number(char *file_name);
char	ft_get_obstacle(char *file_name);
char	ft_get_void(char *file_name);
char	ft_get_full(char *file_name);
int		ft_verify_returns(char *file_name);
int		ft_verify_columns(char *argv);
int		ft_verify_map(char *argv);
char	**ft_create_map(int row, int col);
char	**ft_read_map(char *argv);
t_bsq	ft_find_bsq_in_matrix(int **matrix, int c, int l);
int		**ft_find_solution(char **map, int l, int c, char obst);
int		ft_min(int a, int b, int c);

#endif