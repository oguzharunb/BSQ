/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:52:50 by yusudemi          #+#    #+#             */
/*   Updated: 2024/09/04 22:26:41 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_find_bsq(t_data *d, t_us **mx)
{
	t_us	i;
	t_us	j;

	i = 0;
	while (i < d->line)
	{
		j = 0;
		while (j < d->col)
		{
			if (mx[i][j] > d->bsq_size)
			{
				d->bsq_x = i;
				d->bsq_y = j;
				d->bsq_size = mx[i][j];
			}
			j++;
		}
		i++;
	}
}

t_bool	ft_process_end_check(t_data *d, t_location *loc, int i)
{
	if (d->raw_map[i] == '\n')
	{
		if (loc->y != d->col)
			return (0);
	}
	return (1);
}

t_bool	ft_checker(t_data *d, t_us **matrix, t_ul *i, t_location *loc)
{
	if (d->raw_map[*i] == '\n')
	{
		loc->x += 1;
		loc->y = 0;
		(*i)++;
	}
	if ((d->raw_map[*i] == d->empty || d->raw_map[*i] == d->obstacle)
		&& loc->x < d->line && loc->y < d->col && ft_is_pable(d->raw_map[*i]))
	{
		matrix[loc->x][loc->y] = d->raw_map[*i] == d->empty;
		return (2);
	}
	else if (!d->raw_map[*i])
		return (1);
	else
		return (0);
}

t_bool	ft_write_to_mx(t_data *d, t_us **matrix)
{
	t_ul		i;
	t_location	loc;
	t_bool		ret;
	t_ul		nl;

	i = d->map_start;
	loc.x = 0;
	loc.y = 0;
	nl = 0;
	while (d->raw_map[i])
	{
		if (d->raw_map[i] == '\n')
			nl++;
		if (!ft_process_end_check(d, &loc, i))
			return (0);
		ret = ft_checker(d, matrix, &i, &loc);
		if (ret != 2)
			return (ret);
		loc.y++;
		i++;
	}
	if (nl != d->line)
		return (0);
	return (1);
}

t_bool	ft_solve(t_data *d, t_us **mx)
{
	int		j;
	int		i;
	t_us	m;

	if (!ft_write_to_mx(d, mx))
		return (ft_err_message("map error\n"));
	i = d->line;
	while (--i >= 0)
	{
		j = d->col;
		while (--j >= 0)
		{
			if (mx[i][j] == 0)
				mx[i][j] = 0;
			else if ((t_us)i == d->line - 1 || (t_us)j == d->col - 1)
				mx[i][j] = 1;
			else
			{
				m = ft_m(mx[i][j + 1], mx[i + 1][j], mx[i + 1][j + 1]);
				mx[i][j] = m + 1;
			}
		}
	}
	ft_find_bsq(d, mx);
	return (1);
}
