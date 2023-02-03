/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:22 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/03 14:27:03 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (map_info->texture.floor == -1 || map_info->texture.ceiling == -1)
		exit_error("texture error\n");
	return ;
}

void	search_adjoin(t_map_info *map_info, t_bfs *bfs, int y, int x)
{
	int	i;
	int	ny;
	int	nx;

	i = 0;
	while (i < 4)
	{
		ny = y + bfs->dy[i];
		nx = x + bfs->dx[i];
		if (is_valid(map_info, ny, nx))
		{
			if (bfs->visited[ny][nx] == 0 && (map_info->map[ny][nx] == '0'))
			{
				q_append(bfs->q, new_arr(ny, nx));
				bfs->visited[ny][nx] = 1;
			}
			else if (bfs->visited[ny][nx] == 0 && map_info->map[ny][nx] == ' ')
				exit_error("map error\n");
		}
		else
			exit_error("map error\n");
		i++;
	}
	return ;
}

void	check_wall(t_map_info *map_info)
{
	t_bfs	bfs;
	int		*now;
	int		y;
	int		x;

	init_bfs(map_info, &bfs);
	q_append(bfs.q, new_arr(map_info->player.pos_y, map_info->player.pos_x));
	bfs.visited[(int)map_info->player.pos_y][(int)map_info->player.pos_x] = 1;
	while (!q_empty(bfs.q))
	{
		now = q_pop(bfs.q);
		y = now[0];
		x = now[1];
		search_adjoin(map_info, &bfs, y, x);
		free(now);
	}
	free_double_int(bfs.visited, map_info->height);
	q_clear(bfs.q);
	return ;
}

void	check_map_argc(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->widths[i])
		{
			if (map_info->map[i][j] != '0' && map_info->map[i][j] != '1' &&
				map_info->map[i][j] != 'S' && map_info->map[i][j] != 'N' &&
				map_info->map[i][j] != 'W' && map_info->map[i][j] != 'E' &&
				map_info->map[i][j] != ' ')
			{
				exit_error("invalid map element\n");
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_map(t_map_info *map_info)
{
	check_texture(map_info);
	check_map_argc(map_info);
	check_wall(map_info);
	return ;
}
