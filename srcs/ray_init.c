/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:00 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:29:01 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_init_2(t_ray *ray, t_player *player)
{
	if (ray->rayDirX < 0)
	{
    	ray->stepX = -1;
    	ray->sideDistX = (player->pos_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - player->pos_x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
    	ray->stepY = -1;
		ray->sideDistY = (player->pos_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - player->pos_y) * ray->deltaDistY;
	}
}

void	ray_init(t_ray *ray, t_player *player, t_dis_size dis_size, int x)
{
	ray->cameraX = 2 * x / (double)dis_size.width - 1;
	if ((dis_size.width - 1) == x)
		ray->cameraX = 1;
	ray->rayDirX = player->dir_x + player->plane_x * ray->cameraX;
	ray->rayDirY = player->dir_y + player->plane_y * ray->cameraX;
	ray->mapX = (int)player->pos_x;
	ray->mapY = (int)player->pos_y;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray_init_2(ray, player);
}
