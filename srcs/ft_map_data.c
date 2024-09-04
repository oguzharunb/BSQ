/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:52:45 by yusudemi          #+#    #+#             */
/*   Updated: 2024/09/04 20:56:34 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	ft_fill_map_data(t_data *d)
{
	t_ui	i;
	t_ui	x;

	i = 0;
	while (d->raw_map[i] && d->raw_map[i] != '\n')
		i++;
	if (!d->raw_map[i] || !d->raw_map[i + 1])
		return (ft_err_message("map error\n"));
	d->map_start = i + 1;
	d->filler = d->raw_map[--i];
	d->obstacle = d->raw_map[--i];
	d->empty = d->raw_map[--i];
	if (d->empty == d->filler || d->empty == d->obstacle
		|| d ->filler == d->obstacle)
		return (ft_err_message("map error\n"));
	x = 0;
	d->line = 0;
	while (x < i)
	{
		if (d->raw_map[x] > '9' || d->raw_map[x] < '0')
			return (ft_err_message("map error\n"));
		d->line = d->line * 10 + d->raw_map[x++] - '0';
	}
	return (1);
}

t_bool	ft_read_col(t_data *d)
{
	t_ui	i;

	if (d->line == 0)
		return (ft_err_message("map error\n"));
	i = d->map_start;
	while (d->raw_map[i] && d->raw_map[i] != '\n')
		i++;
	d->col = i - d->map_start;
	if (d->col == 0)
		return (ft_err_message("map error\n"));
	return (1);
}
