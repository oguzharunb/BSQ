/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:52:42 by yusudemi          #+#    #+#             */
/*   Updated: 2024/09/04 21:08:13 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_data_placeholder(t_data *d)
{
	d->line = 0;
	d->col = 0;
	d->bsq_x = 0;
	d->bsq_size = 0;
	d->bsq_y = 0;
	d->raw_map = NULL;
}

t_us	**ft_create_matrix(t_data *d)
{
	t_us	**matrix;
	t_ui	i;

	matrix = malloc(sizeof(t_us *) * d->line);
	if (!matrix)
	{
		ft_err_message("Memory allocation failed\n");
		return (NULL);
	}
	i = 0;
	while (i < d->line)
	{
		matrix[i] = malloc(sizeof(t_us) * d->col);
		if (!matrix[i])
			return (ft_free_matrix_i(matrix, i));
		i++;
	}
	return (matrix);
}
