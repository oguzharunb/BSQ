/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:49:20 by obastug           #+#    #+#             */
/*   Updated: 2024/09/04 21:18:47 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	ft_free_matrix(t_data *d, t_us **matrix, t_bool err)
{
	unsigned int	i;

	i = 0;
	while (i < d->line)
	{
		free(matrix[i]);
		i++;
	}
	if (d->col != 0)
		free(matrix);
	if (err)
		ft_err_message("map error\n");
	return (1);
}

t_us	**ft_free_matrix_i(t_us **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}
