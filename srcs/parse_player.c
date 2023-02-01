/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:30:05 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/01 19:39:15 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_dir(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
}

void	parse_plane(t_player *player, char c)
{
	if (c == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (c == 'W')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

void	parse_player(t_map_info *map_info)
{
	int		x;
	int		y;
	char	c;

	x = (int)map_info->player.pos_x;
	y = (int)map_info->player.pos_y;
	c = map_info->map[y][x];
	parse_dir(&map_info->player, c);
	parse_plane(&map_info->player, c);
}
