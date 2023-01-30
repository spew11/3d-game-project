/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:09:56 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:29:38 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_r(t_player *player)
{
	double	old_x;
	double	old_y;

	old_x = player->plane_x;
	old_y = player->plane_y;
	player->plane_x = old_x * cos(-THETA * PI / \
	180) + old_y * sin(-THETA * PI / 180);
	player->plane_y = -old_x * sin(-THETA * PI / \
	180) + old_y * cos(-THETA * PI / 180);
	old_x = player->dir_x;
	old_y = player->dir_y;
	player->dir_x = old_x * cos(-THETA * PI / \
	180) + old_y * sin(-THETA * PI / 180);
	player->dir_y = -old_x * sin(-THETA * PI / \
	180) + old_y * cos(-THETA * PI / 180);
}

void	rotate_l(t_player *player)
{
	double	old_x;
	double	old_y;

	old_x = player->plane_x;
	old_y = player->plane_y;
	player->plane_x = old_x * cos(THETA * PI / \
	180) + old_y * sin(THETA * PI / 180);
	player->plane_y = -old_x * sin(THETA * PI / \
	180) + old_y * cos(THETA * PI / 180);
	old_x = player->dir_x;
	old_y = player->dir_y;
	player->dir_x = old_x * cos(THETA * PI / \
	180) + old_y * sin(THETA * PI / 180);
	player->dir_y = -old_x * sin(THETA * PI / \
	180) + old_y * cos(THETA * PI / 180);
}
