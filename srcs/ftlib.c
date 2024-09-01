#include "../includes/bsq.h"

//just moves the cursor
void	ft_cursor_to_next_line(int fd)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc((4096) * sizeof(char));
	if (buf == NULL)
		return ;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
		{
			free(buf);
			break ;
		}
		i++;
	}
}

//returns how many columns in that line
int	ft_get_next_columns(int fd)
{
	char	buf;
	int		j;

	j = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
		j++;
	}
	return (j + 1);
}
