#include "../includes/bsq.h"

t_us	**ft_generate_matrix(t_us l, t_us c)
{
	t_us	**sol_map;
	t_us	i;

	sol_map = (t_us **)malloc(l * sizeof(t_us *));
	if (!sol_map)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sol_map[i] = (t_us *)malloc(c * sizeof(t_us));
		if (!sol_map[i])
			return (NULL);
		i++;
	}
	return (sol_map);
}

#include <stdio.h>

t_us	**ft_solve(char **map, t_us l, t_us c, char obst)
{
	t_us		**mx;
	short		i;
	short		j;
	t_us		min;

	i = l;
	mx = ft_generate_matrix(l, c);
	write(1, "solve started", 14);
	while (--i >= 0)
	{
		j = c;
		while (--j >= 0)
		{
			if (map[i][j] == obst)
				mx[i][j] = 0;
			else if (i == l - 1 || j == c - 1)
				mx[i][j] = 1;
			else
			{
				min = ft_min(mx[i][j + 1], mx[i + 1][j], mx[i + 1][j + 1]);
				mx[i][j] = min + 1;
			}
		}
	}
	return (mx);
}

t_bsq	ft_find_bsq_in_matrix(t_us **matrix, t_us l, t_us c)
{
	t_us		i;
	t_us		j;
	t_bsq		bsq;

	i = -1;
	bsq.size = 0;
	while (++i < l)
	{
		j = -1;
		while (++j < c - 1)
		{
			if (matrix[i][j] > bsq.size)
			{
				bsq.x = j;
				bsq.y = i;
				bsq.size = matrix[i][j];
			}
			ft_putnbr(matrix[i][j]);
		}
		ft_putchar('\n');
	}
	return (bsq);
}
