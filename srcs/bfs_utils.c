/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjilee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:20 by eunjilee          #+#    #+#             */
/*   Updated: 2023/02/03 14:32:37 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid(t_map_info *map_info, int y, int x)
{
	if (y >= 0 && y < map_info->height && x >= 0)
	{
		if (x < map_info->widths[y])
		{
			return (1);
		}
	}
	return (0);
}

void	init_visited(t_map_info *map_info, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * map_info->widths[i]);
		if (!visited[i])
		{
			exit_error("malloc failed\n");
		}
		j = 0;
		while (j < map_info->widths[i])
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return ;
}

void	init_dydx(int *dy, int *dx)
{
	dy[0] = 1;
	dy[1] = -1;
	dy[2] = 0;
	dy[3] = 0;
	dx[0] = 0;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = -1;
	return ;
}

int	*new_arr(int a, int b)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
	{
		exit_error("malloc failed\n");
	}
	arr[0] = a;
	arr[1] = b;
	return (arr);
}

void	init_bfs(t_map_info *map_info, t_bfs *bfs)
{
	bfs->q = (t_queue *)malloc(sizeof(t_queue) * 1);
	if (!(bfs->q))
		exit_error("malloc failed\n");
	bfs->q->front = 0;
	bfs->visited = (int **)malloc(sizeof(int *) * (map_info->height));
	if (!(bfs->visited))
		exit_error("malloc failed\n");
	init_visited(map_info, bfs->visited);
	init_dydx(bfs->dy, bfs->dx);
}
