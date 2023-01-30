/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:30 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:29:31 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	skip_white_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	return (i);
}

void	alloc_buffer(t_texture *texture, t_dis_size dis_size)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = dis_size.width;
	height = dis_size.height;
	texture->buffer = (int **)malloc(sizeof(int *) * height * width);
	if (!texture->buffer)
		exit_error("malloc erfror\n");
	i = 0;
	while (i < height)
	{
		texture->buffer[i] = (int *)malloc(sizeof(int) * width);
		if (!texture->buffer[i])
			exit_error("malloc efrror\n");
		j = 0;
		while (j < width)
			texture->buffer[i][j++] = 0;
		i++;
	}
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
	else if (line[idx] == 'F')
		parse_f(map_info, line, idx);
	else if (line[idx] == 'C')
		parse_c(map_info, line, idx);
	else
		return (0);
	return (1);
}

void	parse_player_pos(t_map_info *map_info)
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
				map_info->player.pos_y = i + 0.5;
				map_info->player.pos_x = j + 0.5;
				flag = 1;
			}
			j++;
		}
		i++;
	}
}

void	get_widths(t_map_info *map_info)
{
	int	i;

	map_info->widths = (int *)malloc(sizeof(int) * map_info->height);
	i = 0;
	while (i < map_info->height)
	{
		map_info->widths[i] = ft_strlen(map_info->map[i]);
		i++;
	}
	return ;
}

void	init_interrupt(t_interrupt *interrupt)
{
	interrupt->w = 0;
	interrupt->s = 0;
	interrupt->a = 0;
	interrupt->d = 0;
	interrupt->l = 0;
	interrupt->r = 0;
}

void	init_map_info(t_map_info *map_info, int fd)
{
	char	*arr_line;

	arr_line = get_next_line(fd);
	if (!arr_line)
		exit_error("Empty map !\n");
	int config_cnt = 0;
	while (arr_line && config_cnt < 7)
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
	alloc_buffer(&map_info->texture, map_info->dis_size);
	while (arr_line[0] == '\n') {
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	while (arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, arr_line);
		map_info->height++;
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	map_info->map = ft_split_nl(map_info->map_line, '\n');
	get_widths(map_info);
	parse_player_pos(map_info);
	parse_player(map_info);
	init_interrupt(&map_info->interrupt);
	map_info->map[(int)map_info->player.pos_y][(int)map_info->player.pos_x] = '0';
}
