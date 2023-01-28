#include "cub3D.h"

void	dda(t_map_info *map_info, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = WALL_X; // 0
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = WALL_Y; // 1
		}
		if (map_info->map[ray->mapY][ray->mapX] == '1')
			hit = 1;
		hit = 0;
		if (ray->side == WALL_X)
			ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
		else
			ray->perpWallDist = ray->sideDistY - ray->deltaDistY;
	}
}

void	raycast(t_map_info *map_info, t_dis_size dis_size)
{
	int	x;

	x = 0;
	while (x < dis_size.width)
	{
		ray_init(&map_info->ray, &map_info->player, map_info->dis_size, x);
		dda(map_info, &map_info->ray);
		x++;
	}
}
