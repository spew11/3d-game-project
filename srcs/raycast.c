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
	}
	if (ray->side == WALL_X)
		ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
	else
		ray->perpWallDist = ray->sideDistY - ray->deltaDistY;
}

void	draw_wall_2(t_ray *ray, t_texture *texture, int x)
{
	int		color;
	int		y;

	y = ray->start;
	while (y < ray->end)
	{
		ray->tex_y = (int)ray->texpos & (TEX_H - 1);
		if (ray->side == WALL_X)
		{
			if (ray->rayDirX >= 0)
				color = texture->walls_img[EA][TEX_H * ray->tex_y + ray->tex_x];
			else
				color = texture->walls_img[WE][TEX_H * ray->tex_y + ray->tex_x];
		}
		else if (ray->side == WALL_Y)
		{
			if (ray->rayDirY >= 0)
				color = texture->walls_img[SO][TEX_H * ray->tex_y + ray->tex_x];
			else
				color = texture->walls_img[NO][TEX_H * ray->tex_y + ray->tex_x];
		}
		texture->buffer[y][x] = color;
		ray->texpos += ray->ratio;
		y++;
	}
}

void	draw_wall(t_ray *ray, t_texture *texture, t_player *player, t_dis_size dis_size)
{
	double	wall;

	if (ray->side == WALL_X)
		wall = player->pos_y + (ray->perpWallDist * ray->rayDirY);
	else
		wall = player->pos_x + (ray->perpWallDist * ray->rayDirX);
	wall = wall - floor(wall);
	ray->tex_x = (int)(wall * (double)TEX_W);
	if (ray->side == WALL_X && ray->rayDirX < 0)
		ray->tex_x = TEX_W - ray->tex_x - 1;
	if (ray->side == WALL_Y && ray->rayDirY > 0)
		ray->tex_x = TEX_W - ray->tex_x - 1;
	ray->line = (int)(dis_size.height / ray->perpWallDist);
	ray->start = dis_size.height / 2 - ray->line / 2;
	ray->end = dis_size.height / 2 + ray->line / 2;
	if (ray->start < 0)
		ray->start = 0;
	if (ray->end >= dis_size.height)
		ray->end = dis_size.height;
	ray->ratio = 1.0 * TEX_H / ray->line;
	ray->texpos = (ray->start - dis_size.height / 2 + ray->line / 2) * ray->ratio;
}

void	raycast(t_map_info *map_info, t_dis_size dis_size)
{
	int	x;

	x = 0;
	while (x < dis_size.width)
	{
		ray_init(&map_info->ray, &map_info->player, map_info->dis_size, x);
		dda(map_info, &map_info->ray);
		draw_wall(&map_info->ray, &map_info->texture, &map_info->player, map_info->dis_size);
		draw_wall_2(&map_info->ray, &map_info->texture, x);
		x++;
	}
}
