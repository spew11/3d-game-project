/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:43:41 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:43:43 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	print_player_k(t_map_info map_info);

int	exit_game(t_map_info *map_info)
{
	printf("close\n");
	mlx_destroy_window(map_info->mlx, map_info->win);
	// ft_free_final(map_info);
	exit(0);
}

int	key_press(int keycode, t_map_info *map_info)
{
	if (keycode == KEY_W)
		move_w(map_info, &map_info->player);
	else if (keycode == KEY_S)
		move_s(map_info, &map_info->player);
	else if (keycode == KEY_A)
		move_a(map_info, &map_info->player);
	else if (keycode == KEY_D)
		move_d(map_info, &map_info->player);
	else if (keycode == KEY_L)
		rotate_l(map_info, &map_info->player);
	else if (keycode == KEY_R)
		rotate_r(map_info, &map_info->player);
	else if (keycode == KEY_ESC)
		exit_game(map_info);
	print_player_k(*map_info);
	return (0);
}

void	print_player_k(t_map_info map_info)
{
	printf("\n");
	printf("========= player ==========\n");
	printf("pos_x=%lf pos_y=%lf\n", map_info.player.pos_x, map_info.player.pos_y);
	printf("dir_x=%lf dir_y=%lf	%lf\n", map_info.player.dir_x, map_info.player.dir_y, pow(map_info.player.dir_x, 2) + pow(map_info.player.dir_y, 2));
	printf("plane_x=%lf plane_y=%lf	%lf\n", map_info.player.plane_x, map_info.player.plane_y, pow(map_info.player.plane_x, 2) + pow(map_info.player.plane_y, 2));
}