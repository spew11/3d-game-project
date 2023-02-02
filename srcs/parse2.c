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

int	init_config(t_map_info *map_info, char *line, int idx)
{
	if (!ft_strncmp(line + idx, "EA", 2))
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
		exit_error("invalid configures\n");
	return (1);
}

void	parse_player_pos(t_map_info *map_info)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
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
	return ;
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
