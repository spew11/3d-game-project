#include "cub3D.h"

void	ray_init(t_map_info *map_info, t_ray *ray, t_player *player)
{
	// cameraX = 2 * x / map_info->dis_size.width - 1;
	// rayDirX = dirX + cameraX * planeX;
	// rayDirY = dirY + cameraX * planeY;
	if (ray->rayDirX < 0)
    	ray->stepX = -1;
	else
    	ray->stepX = 1;
	if (ray->rayDirY < 0)
    	ray->stepY = -1;
	else
		ray->stepY = 1;
	if (ray->rayDirX < 0)
    	ray->sideDistX = (player->pos_x - ray->mapX) * ray->deltaDistX;
	else
    	ray->sideDistX = (ray->mapX + 1 - player->pos_x) * ray->deltaDistX;
	if (ray->rayDirY < 0)
		ray->sideDistY = (player->pos_y - ray->mapY) * ray->deltaDistY;
	else
		ray->sideDistY = (ray->mapY + 1 - player->pos_y) * ray->deltaDistY;

}

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
