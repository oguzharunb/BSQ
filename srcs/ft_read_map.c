/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:50:16 by obastug           #+#    #+#             */
/*   Updated: 2024/09/04 19:55:16 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	ft_reader(t_data *d, int fd, long buffer_size, long size)
{
	char	*buffer;
	long	ret;

	buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (ft_err_message("Memory allocation failed\n"));
	ret = read(fd, buffer, buffer_size);
	buffer[ret] = '\0';
	while (ret != 0 && ret != -1)
	{
		d->raw_map = ft_strsjoin(d->raw_map, size, buffer, buffer_size);
		if (!d->raw_map)
			return (ft_err_message("Memory allocation failed\n"));
		size += ret;
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (1);
}

t_bool	ft_read_map(t_data *d, int fd, long buffer_size)
{
	long	ret;

	d->raw_map = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!d->raw_map)
		return (ft_err_message("Memory allocation failed\n"));
	ret = read(fd, d->raw_map, buffer_size);
	d->raw_map[ret] = '\0';
	if (ret != 0 && ret != -1)
		if (!ft_reader(d, fd, buffer_size, ret))
			return (0);
	return (1);
}

t_bool	ft_read_stdin(t_data *d)
{
	if (!ft_read_map(d, STDIN_FILENO, BUFFER_STDIN))
		return (0);
	if (!ft_fill_map_data(d) || !ft_read_col(d))
		return (0);
	return (1);
}

t_bool	ft_read_file(t_data *d, char *file)
{
	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_err_message("File reading failed\n"));
	if (!ft_read_map(d, d->fd, BUFFER_SIZE))
	{
		close(d->fd);
		return (0);
	}
	if (!ft_fill_map_data(d) || !ft_read_col(d))
		return (0);
	close(d->fd);
	return (1);
}
