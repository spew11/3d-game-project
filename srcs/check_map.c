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
	i = 0;
	while (i < 3)
	{
		if (!map_info->texture.floor[i] || !map_info->texture.ceil[i])
			exit_error("texture error\n");
		i++;
	}
}

int is_valid(t_map_info *map_info, int y, int x)
{
	if (y >= 0 && y < map_info->height && x >= 0) {
		if (x < map_info->widths[y]) {
			return (1);
		}
	}
	return (0);
}


void check_wall(t_map_info *map_info)
{
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	int **visited = (int **)malloc(sizeof(int *) * (map_info->height));
	if (!visited)
		exit_error("malloc failed\n");
	for (int i = 0; i < map_info->height; i++)
	{
		visited[i] = (int *)malloc(sizeof(int) * map_info->widths[i]);
		for (int j = 0; j < map_info->widths[i]; j++)
		{
			visited[i][j] = 0;
		}
	}
	t_queue	*q = (t_queue *)malloc(sizeof(t_queue) * 1);
	q->front = 0;
	q_append(q, new_arr(map_info->player.y, map_info->player.x));
	visited[map_info->player.y][map_info->player.x] = 1;
	while (!q_empty(q))
	{
		int *now = q_pop(q);
		int y = now[0];
		int x = now[1];
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_valid(map_info, ny, nx))
			{
				if (visited[ny][nx] == 0 && (map_info->map[ny][nx] == '0' || map_info->map[ny][nx] == '2'))
				{
					q_append(q, new_arr(ny, nx));
					visited[ny][nx] = 1;
				}
				else if (visited[ny][nx] == 0  && map_info->map[ny][nx] == ' ') {
					exit_error("map must be surrounded by wall\n");
				}
			}
			else
			{
				exit_error("map must be surrounded by wall\n");
			}
		}
	}
	return ;
}

void	check_map(t_map_info *map_info)
{
	//	check map_info error
	check_texture(map_info);
	//다른 숫자 있는지 체크하기
	for (int i = 0; i < map_info->height; i++) {
		for (int j = 0; j < map_info->widths[i]; j++) {
			if (map_info->map[i][j] != '0' && map_info->map[i][j] != '1' &&
				map_info->map[i][j] != '2' && map_info->map[i][j] != 'N' &&
				map_info->map[i][j] != 'S' && map_info->map[i][j] != 'W' &&
				map_info->map[i][j] != 'E' && map_info->map[i][j] != ' ')
			{
				exit_error("invalid map element\n");
			}
		}
	}
	check_wall(map_info);
}
