/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:43:41 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/02 13:03:02 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_player_k(t_map_info map_info);

int	exit_game(t_map_info *map_info)
{
	printf("close\n");
	mlx_destroy_window(map_info->mlx, map_info->win);
	exit(0);
}

int	interrupt(t_map_info *map_info, t_interrupt interrupt)
{
	if (interrupt.w && !interrupt.s)
		move_w(map_info, &map_info->player);
	if (interrupt.s && !interrupt.w)
		move_s(map_info, &map_info->player);
	if (interrupt.a && !interrupt.d)
		move_a(map_info, &map_info->player);
	if (interrupt.d && !interrupt.a)
		move_d(map_info, &map_info->player);
	if (interrupt.l && !interrupt.r)
		rotate_l(&map_info->player);
	if (interrupt.r && !interrupt.l)
		rotate_r(&map_info->player);
	return (0);
}

int	key_press(int keycode, t_map_info *map_info)
{
	if (keycode == KEY_W)
		map_info->interrupt.w = 1;
	if (keycode == KEY_S)
		map_info->interrupt.s = 1;
	if (keycode == KEY_A)
		map_info->interrupt.a = 1;
	if (keycode == KEY_D)
		map_info->interrupt.d = 1;
	if (keycode == KEY_L)
		map_info->interrupt.l = 1;
	if (keycode == KEY_R)
		map_info->interrupt.r = 1;
	if (keycode == KEY_ESC)
		exit_game(map_info);
	return (0);
}

int	key_release(int keycode, t_map_info *map_info)
{
	if (keycode == KEY_W)
		map_info->interrupt.w = 0;
	if (keycode == KEY_S)
		map_info->interrupt.s = 0;
	if (keycode == KEY_A)
		map_info->interrupt.a = 0;
	if (keycode == KEY_D)
		map_info->interrupt.d = 0;
	if (keycode == KEY_L)
		map_info->interrupt.l = 0;
	if (keycode == KEY_R)
		map_info->interrupt.r = 0;
	return (0);
}
