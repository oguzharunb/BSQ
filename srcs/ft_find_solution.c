#include "../includes/bsq.h"


int	**ft_generate_solution_matrix(int l, int c)
{
	int	**sol_map;
	int	i;

	sol_map = malloc(l * sizeof(int));
	if (!sol_map)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sol_map[i] = malloc(c * sizeof(int));
		if (!sol_map[i])
			return (NULL);
	}
	return (sol_map);
}

int	**ft_find_solution(char **map, int l, int c, char obst)
{
	int		**matrix;
	int		i;
	int		j;
	int		min;

	i = l;
	j = c;
	matrix = ft_generate_solution_matrix(l, c);
	while (--i >= 0)
	{
		while (--j >= 0)
		{
			if (map[i][j] == obst)
				matrix[i][j] = 0;
			else if (i == l - 1 || j == c - 1)
				matrix[i][j] = 1;
			else
			{
				min = ft_min(map[i][j - 1], map[i - 1][j], map[i - 1][j - 1]);
				matrix[i][j] = min + 1;
			}
		}
	}
	write(1, );
	return (matrix);
}

t_bsq	ft_find_bsq_in_matrix(int **matrix, int c, int l)
{
	int		i;
	int		j;
	t_bsq	bsq;

	i = -1;
	j = -1;
	bsq.size = 0;
	while (++i < l)
	{
		while (++j < c)
		{
			if (matrix[i][j] > bsq.size)
			{
				bsq.x = c;
				bsq.y = l;
				bsq.size = matrix[i][j];
			}
		}
	}
	return (bsq);
}
