/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:50:13 by obastug           #+#    #+#             */
/*   Updated: 2024/09/04 22:00:32 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_put_bsq(t_data *d)
{
	t_ui	i;
	t_ui	j;

	i = d->bsq_x;
	while (i < d->bsq_x + d->bsq_size)
	{
		j = d->bsq_y;
		while (j < d->bsq_y + d->bsq_size)
		{
			d->raw_map[(i * (d->col + 1)) + j + d->map_start] = d->filler;
			j++;
		}
		i++;
	}
}

void	ft_print_solution(t_data *d)
{
	ft_put_bsq(d);
	write(1, &d->raw_map[d->map_start], d->line * (d->col + 1));
}
