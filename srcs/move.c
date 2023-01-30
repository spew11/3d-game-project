/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:09:56 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:29:10 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_w(t_map_info *map_info, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->dir_x * STEP;
	new_y = player->dir_y * STEP;
	if (map_info->map[(int)(player->pos_y)][\
	(int)(player->pos_x + new_x * WALLDIST)] == '0')
		player->pos_x += new_x;
	if (map_info->map[(int)(player->pos_y + \
	new_y * WALLDIST)][(int)(player->pos_x)] == '0')
		player->pos_y += new_y;
}

void	move_s(t_map_info *map_info, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->dir_x * STEP;
	new_y = player->dir_y * STEP;
	if (map_info->map[(int)(player->pos_y)][\
	(int)(player->pos_x - new_x * WALLDIST)] == '0')
		player->pos_x -= new_x;
	if (map_info->map[(int)(player->pos_y - \
	new_y * WALLDIST)][(int)(player->pos_x)] == '0')
		player->pos_y -= new_y;
}

void	move_a(t_map_info *map_info, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->dir_x * STEP;
	new_y = player->dir_y * STEP;
	if (map_info->map[(int)(player->pos_y)][\
	(int)(player->pos_x + new_y * WALLDIST)] == '0')
		player->pos_x += new_y;
	if (map_info->map[(int)(player->pos_y - \
	new_x * WALLDIST)][(int)(player->pos_x)] == '0')
		player->pos_y -= new_x;
}

void	move_d(t_map_info *map_info, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->dir_x * STEP;
	new_y = player->dir_y * STEP;
	if (map_info->map[(int)(player->pos_y)][\
	(int)(player->pos_x - new_y * WALLDIST)] == '0')
		player->pos_x -= new_y;
	if (map_info->map[(int)(player->pos_y + \
	new_x * WALLDIST)][(int)(player->pos_x)] == '0')
		player->pos_y += new_x;
}
