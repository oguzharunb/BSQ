/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:50:09 by obastug           #+#    #+#             */
/*   Updated: 2024/09/04 21:27:58 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	ft_clear(t_data *d, t_us **mx, t_bool ret)
{
	if (d->raw_map)
		free(d->raw_map);
	if (mx)
		ft_free_matrix(d, mx, 0);
	return (ret);
}

t_bool	ft_bsq(t_data *d, char *file)
{
	t_us	**matrix;

	ft_data_placeholder(d);
	if (!file)
	{
		if (!ft_read_stdin(d))
			return (ft_clear(d, NULL, 0));
	}
	else
	{
		if (!ft_read_file(d, file))
			return (ft_clear(d, NULL, 0));
	}
	matrix = ft_create_matrix(d);
	if (!matrix)
		return (ft_clear(d, matrix, 0));
	if (!ft_solve(d, matrix))
		return (ft_clear(d, matrix, 0));
	ft_print_solution(d);
	return (ft_clear(d, matrix, 0));
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_bsq(&d, argv[i]);
			i++;
		}
		if (i < argc)
			return (0);
	}
	else
		return (ft_bsq(&d, NULL));
	return (0);
}
