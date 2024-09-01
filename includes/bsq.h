/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:29:50 by obastug           #+#    #+#             */
/*   Updated: 2024/09/01 13:40:36 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define SUCCESS 0
# define ERR_MAP 1
# define ERR_MEMORY 2
# define ERR_NO_FILE 3
# define ERR_COL 4
# define ERR_LINE 5
# define ERR_RET 6
# define ERR_CHARS 7
# define ERR_COL_N 8
# define ERR_LINE_N 9

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
int		ft_verify_map(char *argv);

typedef struct s_map_data
{
	char	empty;
	char	obst;
	char	full;
	int		file_size;
	int		line;
}	t_map_data;
#endif
