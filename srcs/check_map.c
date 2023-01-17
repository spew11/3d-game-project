#include "cub3D.h"

void	check_texture(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!map_info->texture.walls[i])
			exit_error("texture error\n");
		i++;
	}
	if (!map_info->texture.item)
		exit_error("item error\n");
	i = 0;
	while (i < 3)
	{
		if (!map_info->texture.floor[i] || !map_info->texture.ceil[i])
			exit_error("texture error\n");
		i++;
	}
}

void	check_wall(t_map_info *map_info)
{
	
	int	i;
	int	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (i == 0 || i == map_info->height - 1 || j == 0 || j == map_info->width - 1)
			{
				if (map_info->map[i][j] != '1')
				{
					printf("* %d %d: %d\n", i, j, (int)map_info->map[i][j]);
					exit_error("map must be surrounded by walls\n");
				}
			}
			j++;
		}
		i++;
	}
	return ;
}


void	check_map(t_map_info *map_info)
{
	//	check map_info error
	check_texture(map_info);
	check_wall(map_info);
}