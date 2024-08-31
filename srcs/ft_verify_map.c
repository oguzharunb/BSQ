/*
-> new line check
	does line_number data and number of lines in file match?
	is the map rectengular
-> char check
	-> are there any other characters on the map rather than the ones the referred at first
-> does a map exists?

karakter sayısı // i
new line sayacı // baştakine eşit değilse map error
satırdaki karakter sayacı // biri öncekine eşit değilse map error

*/

#include "../includes/bsq.h"

//this file exists because we want to deal with a valid map.
int	ft_verify_chars(char *file_name)
{
	t_map_data map_data;
	int	fd;

	map_data.file_size = ft_size_file(file_name);
	map_data.empty = ft_get_void(file_name);
	map_data.full = ft_get_full(file_name);
	map_data.obst = ft_get_obstacle(file_name);
	map_data.line = ft_get_l_number(file_name);
	fd = open(file_name, O_RDONLY);

}