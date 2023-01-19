#include "cub3D.h"

void	parse_dis_size(t_map_info *map_info, char *line, int idx)
{
	char	**temp;
	int		i;

	temp = ft_split(line + idx, ' ');
	i = 0;
	while (temp[i])
		i++;
	if (i > 3)
		exit_error("format : R width height\n");
	map_info->dis_size.width = ft_atoi(temp[1]);
	map_info->dis_size.height = ft_atoi(temp[2]);
}

void	parse_walls(t_texture *texture, int wall_type, char *line, int idx)
{
	char	**temp;
	temp = ft_split(line + idx, ' ');
	if (count_arr_2(temp) != 2)
		exit_error("incorrect config\n");
	texture->walls[wall_type] = ft_strdup(temp[1]);
	free_arr_2(temp);
}

void	parse_F(t_map_info *map_info, char *line, int idx)
{
	int		i;
	char	**temp;
	char	**temp2;

	temp = ft_split(line + idx, ' ');
	if (count_arr_2(temp) != 2)
		exit_error("incorrect config\n");
	temp2 = ft_split(temp[1], ',');
	if (count_arr_2(temp2) != 3)
		exit_error("incorrect config\n");
	i = 0;
	while (i < 3)
	{
		map_info->texture.floor[i] = atoi(temp2[i]);
		i++;
	}
	free_arr_2(temp);
	free_arr_2(temp2);
}

void	parse_C(t_map_info *map_info, char *line, int idx)
{
	int		i;
	char	**temp;
	char	**temp2;

	temp = ft_split(line + idx, ' ');
	if (count_arr_2(temp) != 2)
		exit_error("incorrect config\n");
	temp2 = ft_split(temp[1], ',');
	if (count_arr_2(temp2) != 3)
		exit_error("incorrect config\n");
	i = 0;
	while (i < 3)
	{
		map_info->texture.ceil[i] = atoi(temp2[i]);
		i++;
	}
	free_arr_2(temp);
	free_arr_2(temp2);
}

void	parse_S(t_map_info *map_info, char *line, int idx)
{
	int		i;
	char	**temp;

	temp = ft_split(line + idx, ' ');
	if (count_arr_2(temp) != 2)
		exit_error("incorrect config\n");
	map_info->texture.item = ft_strdup(temp[1]);
	free_arr_2(temp);
}
