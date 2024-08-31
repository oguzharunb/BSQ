/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:54:23 by obastug           #+#    #+#             */
/*   Updated: 2024/08/31 11:06:30 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

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
		if (buf[i] < '0' && buf[i] > '9')
			break;
		result = (result * 10) + (buf[i] - '0');
		i++;
	}
	close(fd);
	return (result);
}

char	ft_get_obstacle(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if(buf[i] == '\n')
			break;
		i++;
	}
	close(fd);
	return (buf[i - 2]);
}

char	ft_get_void(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if(buf[i] == '\n')
			break;
		i++;
	}
	close(fd);
	return (buf[i - 3]);
}

char	ft_get_filler(char *file_name)
{
	char	buf[80];
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, buf + i, 1))
	{
		if(buf[i] == '\n')
			break;
		i++;
	}
	close(fd);
	return (buf[i - 1]);
}