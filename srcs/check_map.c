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

int is_valid(int width, int height, int y, int x)
{
	return (y >= 0 && y < height && x >= 0 && x < width);
}


void check_wall(t_map_info *map_info)
{
	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, 1, -1};
	int **visited = (int **)malloc(sizeof(int *) * (map_info->height));
	if (!visited)
		exit_error("malloc failed\n");
	for (int i = 0; i < map_info->height; i++) {
		visited[i] = (int *)malloc(sizeof(int) * ft_strlen(map_info->map[i]));
		for (int j = 0; j < ft_strlen(map_info->map[i]); j++) {
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
			if (!is_valid(ft_strlen(map_info->map[ny]), map_info->height, ny, nx))
				exit_error("map must be surrounded by wall\n");
			if (visited[ny][nx] == 0 && (map_info->map[ny][nx] == ' ' || map_info->map[ny][nx] == '0'))
				printf("here\n");
				//q_append(q, new_arr(ny, nx));
				visited[ny][nx] = 1;
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
	check_wall(map_info);
}
