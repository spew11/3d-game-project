#include "cub3D.h"

int	is_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	count_arr_2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}