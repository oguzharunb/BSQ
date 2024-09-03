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

t_us	ft_min(t_us a, t_us b, t_us c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else if (c <= a && c <= b)
		return (c);
	else
		return (1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}