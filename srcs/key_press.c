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
		move_w(map_info);
	else if (keycode == KEY_S)
		move_s(map_info);
	else if (keycode == KEY_A)
		move_a(map_info);
	else if (keycode == KEY_D)
		move_d(map_info);
	else if (keycode == KEY_L)
		move_l(map_info);
	else if (keycode == KEY_R)
		move_r(map_info);
	else if (keycode == KEY_ESC)
		exit_game(map_info);
	return (0);
}
