/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:30 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/03 14:27:45 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	alloc_buffer(t_texture *texture)
{
	int	i;
	int	j;

	texture->buffer = (int **)malloc(sizeof(int *) * DIS_H * DIS_W);
	if (!texture->buffer)
		exit_error("malloc error\n");
	i = 0;
	while (i < DIS_H)
	{
		texture->buffer[i] = (int *)malloc(sizeof(int) * DIS_W);
		if (!texture->buffer[i])
			exit_error("malloc error\n");
		j = 0;
		while (j < DIS_W)
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
	texture->ceiling = -1;
	return ;
}

void	parse_map(t_map_info *map_info, int fd, char **arr_line)
{
	alloc_buffer(&map_info->texture);
	while ((*arr_line)[0] == '\n')
	{
		free(*arr_line);
		*arr_line = get_next_line(fd);
	}
	while (*arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, *arr_line);
		if (!map_info->map_line)
			exit_error("malloc failed\n");
		map_info->height++;
		free(*arr_line);
		*arr_line = get_next_line(fd);
	}
	return ;
}

void	parse_configures(t_map_info *map_info, int fd, char **arr_line, int idx)
{
	*arr_line = get_next_line(fd);
	if (!(*arr_line))
		exit_error("Empty map !\n");
	map_info->config_cnt = 0;
	while (*arr_line && map_info->config_cnt < 6)
	{
		if ((*arr_line)[0] == '\n')
		{
			free(*arr_line);
			*arr_line = get_next_line(fd);
			continue ;
		}
		idx = skip_white_space(*arr_line);
		if (init_config(map_info, *arr_line, idx))
			map_info->config_cnt++;
		free(*arr_line);
		*arr_line = get_next_line(fd);
	}
	return ;
}

void	init_map_info(t_map_info *map_info, int fd)
{
	char	*arr_line;
	int		idx;

	idx = 0;
	init_textures(&(map_info->texture));
	parse_configures(map_info, fd, &arr_line, idx);
	parse_map(map_info, fd, &arr_line);
	map_info->map = ft_split_nl(map_info->map_line, '\n');
	get_widths(map_info);
	parse_player_pos(map_info);
	parse_player(map_info);
	init_interrupt(&map_info->interrupt);
	map_info->map[(int)map_info->player.pos_y][(int)map_info->player.pos_x] = \
		'0';
	return ;
}
