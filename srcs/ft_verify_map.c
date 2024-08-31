/*
-> new line kontrolü
	başta gösterilen yönerge kadar satır var mı?
	harita bir dörtgen şeklinde mi?
-> karakter kontrolü
	-> karakterler başta gösterildiği gibi mi, yoksa başka karakter var mı?
-> harita var mı?

karakter sayısı // i
new line sayacı // baştakine eşit değilse map error
satırdaki karakter sayacı // biri öncekine eşit değilse map error

*/

#include "../includes/bsq.h"

//10.ox
t_map_data	get_map_data(char *map)
{
	int	i;
	int line;
	int	obst;
	int	emty;
	int sqrx;
	i = -1;
	while (map[++i] && map[i] <= '9' && map[i] >= '0')
		line = (line * 10) + (map[i] - '0');
	t_map_data map_data = {map[i], map[i + 1], map[i + 2], line};
	return (map_data);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}


int	ft_verify_map(char *map)
{
	int	i;
	int	new_line;
	int	char_in_line;

	i = 0;

}