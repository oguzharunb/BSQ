/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:08:22 by obastug           #+#    #+#             */
/*   Updated: 2024/08/31 17:29:24 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_size_file(char *file_name)
{
	int		size;
	char	buf;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

void	ft_cursor_to_next_line(int fd)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc(4096 * sizeof(char));
	if (buf == NULL)
		return ;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
}
