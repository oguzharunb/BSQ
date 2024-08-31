/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:38:57 by yusudemi          #+#    #+#             */
/*   Updated: 2024/08/31 20:38:58 by yusudemi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_size_file(char *file_name)
{
    int     size;
	char	buf;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

//This function will give us size of file.
int	ft_size_file(char *file_name)
{
    int     size;
	char	buf;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
    free(buf);
	close(fd);
	return (size);
}

//this file is for getting data of the file like chars, size, line number
int	ft_get_l_number(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;
	int		result;

	result = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] < '0' || buf[i] > '9')
			break ;
		result = (result * 10) + (buf[i] - '0');
		i++;
	}
    free (buf);
	close(fd);
	return (result);
}

int	ft_get_c_number(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;
	int		res;

	res = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	close(fd);
	return (res);
}