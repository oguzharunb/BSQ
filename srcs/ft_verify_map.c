/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:06:48 by obastug           #+#    #+#             */
/*   Updated: 2024/08/31 20:23:50 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-> new line check
	does line_number data and number of lines in file match?
	is the map rectengular
-> char check
-> are there any other characters on the map rather than the 
ones the referred at first
-> does a map exists?

karakter sayısı // i
new line sayacı // baştakine eşit değilse map error
satırdaki karakter sayacı // biri öncekine eşit değilse map error
*/

//this file exists because we want to deal with a valid map.
#include "../includes/bsq.h"

//this function checks if there is another 
//character in map rather than expected ones
int	ft_verify_chars(char *file_name)
{
	t_map_data	map_data;
	int			fd;
	char		*buf;
	int			ret;
	int			i;

	map_data.file_size = ft_size_file(file_name);
	map_data.empty = ft_get_void(file_name);
	map_data.obst = ft_get_obstacle(file_name);
	fd = open(file_name, O_RDONLY);
	ft_cursor_to_next_line(fd);
	buf = malloc(sizeof(char) * (map_data.file_size));
	if (!buf)
		return (NULL);
	ret = read(fd, buf, map_data.file_size);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] != map_data.empty && buf[i]
			!= map_data.obst && buf[i] != '\n')
			return (1);
	}
	close(fd);
	free(buf);
	return (0);
}
