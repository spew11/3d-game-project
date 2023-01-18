#include "cub3D.h"

int	is_white_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_space(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	parse_dir(t_map_info *map_info, char *line)
{
	if (!ft_strncmp(line, "EA", 2))
		parse_walls(&map_info->texture, EA, line);
	else if (!ft_strncmp(line, "WE", 2))
		parse_walls(&map_info->texture, WE, line);
	else if (!ft_strncmp(line, "SO", 2))
		parse_walls(&map_info->texture, SO, line);
	else if (!ft_strncmp(line, "NO", 2))
		parse_walls(&map_info->texture, NO, line);
	else
		return (0);
	return (1);
}

int	init_config(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (1)
	{
		while (is_white_line(map_info->map[i]))
			i++;
		if (map_info->map[i][0] == 'R')
			parse_dis_size(map_info->map[0], map_info);
		else if (parse_dir(map_info, map_info->map[i]))
		{
		}
		else if (map_info->map[i][0] == 'S')
			parse_S(map_info, map_info->map[i]);
		else if (map_info->map[i][0] == 'F')
			parse_F(map_info, map_info->map[i]);
		else if (map_info->map[i][0] == 'C')
			parse_C(map_info, map_info->map[i]);
		else
			break ;
		i++;
	}
	return (i);
}

void	get_map_size(t_map_info *map_info, int idx)
{
	int	i;

	i = idx;
	while (map_info->map[i])
	{
		map_info->height++;
		i++;
	}
	i = 0;
	map_info->width = ft_strlen(map_info->map[idx]);
}

int	parse_map(t_map_info *map_info, int idx)
{
	char	**temp;
	int		i;

	i = idx;
	get_map_size(map_info, idx);
	i = 0;
	temp = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	while (i < map_info->height)
	{
		temp[i] = ft_strdup(map_info->map[idx + i]);
		if (!temp[i])
			exit_error("malloc error\n");
		i++;
	}
	temp[i] = NULL;
	free_arr_2(map_info->map);
	map_info->map = temp;
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
	i = 0;
	while (arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, arr_line);
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	map_info->map = ft_split(map_info->map_line, '\n');
	i = init_config(map_info);
	parse_map(map_info, i);
	parse_start_loc(map_info);
}
