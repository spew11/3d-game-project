#include "cub3D.h"

int	skip_white_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	return (i);
}

int	init_config(t_map_info *map_info, char *line, int idx)
{
	if (line[idx] == 'R')
		parse_dis_size(map_info, line, idx);
	else if (!ft_strncmp(line + idx, "EA", 2))
		parse_walls(&map_info->texture, EA, line, idx);
	else if (!ft_strncmp(line + idx, "WE", 2))
		parse_walls(&map_info->texture, WE, line, idx);
	else if (!ft_strncmp(line + idx, "SO", 2))
		parse_walls(&map_info->texture, SO, line, idx);
	else if (!ft_strncmp(line + idx, "NO", 2))
		parse_walls(&map_info->texture, NO, line, idx);
	else if (line[idx] == 'S')
		parse_S(map_info, line, idx);
	else if (line[idx] == 'F')
		parse_F(map_info, line, idx);
	else if (line[idx] == 'C')
		parse_C(map_info, line, idx);
	else
		return (0);
	return (1);
}

void	get_map_height(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (map_info->map_line[i])
	{
		if (map_info->map_line[i] == '\n')
			map_info->height++;
		i++;
	}
}

int	parse_map(t_map_info *map_info)
{
	char	**temp;
	int		i;
	int		idx;
	// printf("%s\n", map_info->map_line);
	// get_map_height(map_info);
	// printf("!!!: %d\n", map_info->height);

	// /*make widths arr*/
	// map_info->widths = (int *)malloc(sizeof(int) * map_info->height);
	// if (!map_info->widths)
	// 	exit_error("malloc failed\n");
	// i = 0;
	// temp = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	// while (i < map_info->height)
	// {
	// 	temp[i] = ft_strdup(map_info->map[idx + i]);
	// 	map_info->widths[i] = ft_strlen(temp[i]);
	// 	if (!temp[i])
	// 		exit_error("malloc error\n");
	// 	i++;
	// }
	// temp[i] = NULL;
	// free_arr_2(map_info->map);
	// map_info->map = temp;
	return (1);
}

void	parse_start_loc(t_map_info *map_info)
{
	int	i;
	int	j;
	int	flag = 0;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'E' || map_info->map[i][j] == 'W' ||
				map_info->map[i][j] == 'S' || map_info->map[i][j] == 'N')
			{
				if (flag == 1)
					exit_error("player must be one!\n");
				map_info->player.y = i;
				map_info->player.x = j;
				flag = 1;
			}
			j++;
		}
		i++;
	}
}

void	init_map_info(t_map_info *map_info, int fd)
{
	int		i;
	char	*arr_line;

	arr_line = get_next_line(fd);
	if (!arr_line)
		exit_error("Empty map !\n");
	int config_cnt = 0;
	while (arr_line && config_cnt < 8)
	{
		int idx;
		idx = skip_white_space(arr_line);
		if (init_config(map_info, arr_line, idx))
		{
			config_cnt++;
		}
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	while (arr_line[0] == '\n') {
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	while (arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, arr_line);
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	map_info->map = ft_split_nl(map_info->map_line, '\n');
	for (int i = 0; i < 18; i++)
		printf("%s\n", map_info->map[i]);
	parse_map(map_info);
	parse_start_loc(map_info);
}
