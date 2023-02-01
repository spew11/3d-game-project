/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:30 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/01 19:20:09 by eunjilee         ###   ########.fr       */
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
		exit_error("malloc error\n");
	i = 0;
	while (i < height)
	{
		texture->buffer[i] = (int *)malloc(sizeof(int) * width);
		if (!texture->buffer[i])
			exit_error("malloc error\n");
		j = 0;
		while (j < width)
			texture->buffer[i][j++] = 0;
		i++;
	}
}

void	init_textures(t_texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		texture->walls[i] = 0;
		i++;
	}
	texture->floor = -1;
	texture->ceil = -1;
	return ;
}

void	parse_map(t_map_info *map_info, int fd, char *arr_line, int idx)
{
	map_info->config_cnt = 0;
	while (arr_line && map_info->config_cnt < 7)
	{
		idx = skip_white_space(arr_line);
		if (init_config(map_info, arr_line, idx))
			map_info->config_cnt++;
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	if (map_info->config_cnt != 7)
		exit_error("map must have 6 configures\n");
	alloc_buffer(&map_info->texture, map_info->dis_size);
	while (arr_line[0] == '\n')
	{
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
	return ;
}

void	init_map_info(t_map_info *map_info, int fd)
{
	char	*arr_line;
	int		config_cnt;
	int		idx;

	init_textures(&(map_info->texture));
	arr_line = get_next_line(fd);
	if (!arr_line)
		exit_error("Empty map !\n");
	parse_map(map_info, fd, arr_line, idx);
	map_info->map = ft_split_nl(map_info->map_line, '\n');
	get_widths(map_info);
	parse_player_pos(map_info);
	parse_player(map_info);
	init_interrupt(&map_info->interrupt);
	map_info->map[(int)map_info->player.pos_y][(int)map_info->player.pos_x] = \
		'0';
	return ;
}
