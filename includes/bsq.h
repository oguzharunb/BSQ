/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:21:08 by obastug           #+#    #+#             */
/*   Updated: 2024/09/04 22:26:11 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10000000
# define BUFFER_STDIN 500000

typedef char			t_bool;
typedef unsigned short	t_us;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef struct s_data
{
	char	*raw_map;
	t_ul	map_start;
	t_ui	line;
	t_ui	col;
	t_ui	bsq_x;
	t_ui	bsq_y;
	t_ui	bsq_size;
	int		fd;
	char	empty;
	char	obstacle;
	char	filler;
}	t_data;
typedef struct s_location
{
	t_ui	x;
	t_ui	y;
}	t_location;
t_us	**ft_create_matrix(t_data *d);
t_bool	ft_is_pable(char c);
t_bool	ft_process_end_check(t_data *d, t_location *loc, int i);
t_bool	ft_free_matrix(t_data *d, t_us **matrix, t_bool err);
t_us	**ft_free_matrix_i(t_us **matrix, int i);
void	ft_data_placeholder(t_data *d);
t_bool	ft_bsq(t_data *d, char *file);
t_bool	ft_clear(t_data *d, t_us **mx, t_bool ret);
t_bool	ft_err_message(char *str);
t_bool	ft_read_col(t_data *d);
t_ui	ft_m(t_ui a, t_ui b, t_ui c);
char	*ft_strsjoin(char *s1, t_ul size1, char *s2, t_ul size2);
t_bool	ft_fill_map_data(t_data *d);
t_bool	ft_write_to_mx(t_data *d, t_us **matrix);
t_bool	ft_read_map(t_data *d, int fd, long buffer_size);
t_bool	ft_read_file(t_data *d, char *file);
t_bool	ft_read_stdin(t_data *d);
t_bool	ft_reader(t_data *d, int fd, long buffer_size, long size);
t_bool	ft_solve(t_data *d, t_us **matrix);
void	ft_put_bsq(t_data *d);
void	ft_print_solution(t_data *d);
#endif