/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:04 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/02 16:08:46 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	loop(t_map_info *map_info)
{
	draw_updown(&map_info->texture);
	raycast(map_info);
	draw_img(map_info, &map_info->texture);
	interrupt(map_info, map_info->interrupt);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	int			fd;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	init_map_info(&map_info, fd);
	map_info.mlx = mlx_init();
	map_info.win = mlx_new_window(map_info.mlx, DIS_W, DIS_H, "cub3D");
	parse_img(&map_info, &map_info.texture);
	check_map(&map_info);
	map_info.texture.img = mlx_new_image(map_info.mlx,
			DIS_W, DIS_H);
	map_info.texture.data = (int *)mlx_get_data_addr(map_info.texture.img,
			&map_info.texture.bpp, &map_info.texture.size_line,
			&map_info.texture.endian);
	mlx_hook(map_info.win, KEY_EXIT, 0, &exit_game, &map_info);
	mlx_hook(map_info.win, KEY_PRESS, 0, &key_press, &map_info);
	mlx_hook(map_info.win, KEY_RELEASE, 0, &key_release, &map_info);
	mlx_loop_hook(map_info.mlx, &loop, &map_info);
	mlx_loop(map_info.mlx);
}
