/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:04 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/25 21:51:29 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_parsed(t_map_info map_info);
void	print_map_info(t_map_info map_info);
void	print_map_size(t_map_info map_info);
void	print_map_2(t_map_info map_info);
void	print_textures(t_map_info map_info);
void	print_dis_size(t_map_info map_info);
void	print_map(t_map_info map_info);
void	print_player(t_map_info map_info);

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	int			fd;
	/*floor ceiling init*/
	map_info.texture.floor = -1;
	map_info.texture.ceil = -1;
	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	init_map_info(&map_info, fd);

	print_parsed(map_info);

	check_map(&map_info);

	map_info.mlx = mlx_init();
	map_info.win = mlx_new_window(map_info.mlx, \
	map_info.dis_size.width, map_info.dis_size.height, "taehyeong's game");
	// map_info.img = set_img(map_info.mlx);
	// draw_map(map_info);
	mlx_hook(map_info.win, KEY_PRESS, 0, &key_press, &map_info);
	mlx_hook(map_info.win, KEY_EXIT, 0, &exit_game, &map_info);
	mlx_loop(map_info.mlx);
}

void	print_parsed(t_map_info map_info)
{
	print_textures(map_info);
	print_map(map_info);
	print_map_2(map_info);
	print_dis_size(map_info);
	print_map_size(map_info);
	print_map_info(map_info);
	print_player(map_info);
}

void	print_textures(t_map_info map_info)
{
	printf("\n");
	printf("========= textures ========\n");
	for (int i = 0; i < 4; i++)
		printf("wall[%d] = %s\n", i, map_info.texture.walls[i]);
	printf("item = %s\n", map_info.texture.item);
	printf("floor = %x\n", map_info.texture.floor);
	printf("ceil = %x\n", map_info.texture.ceil);
	printf("\n");
}

void	print_dis_size(t_map_info map_info)
{
	printf("\n");
	printf("dis_size = %d %d\n", map_info.dis_size.width, map_info.dis_size.height);
	printf("\n");
}

void	print_map(t_map_info map_info)
{
	printf("\n");
	printf("============ map not splited ========\n");
	printf("%s\n", map_info.map_line);
	printf("=====================================\n");
	printf("\n");
}

void	print_map_2(t_map_info map_info)
{
	printf("\n");
	printf("========== map 2 dimension ==========\n");
	for (int i = 0; map_info.map[i]; i++)
		printf("%s\n", map_info.map[i]);
	printf("=====================================\n");
	printf("\n");
}

void	print_map_size(t_map_info map_info)
{
	printf("\n");
	printf("========== map size==========\n");
	printf("Map size : height = %d\n", map_info.height);
	for (int i = 0; i < map_info.height; i++)
		printf("width[%d]=%d\n", i, map_info.widths[i]);
	printf("\n");
}

void	print_map_info(t_map_info map_info)
{
	printf("\n");
	printf("======== mlx, win =========\n");
	printf("mlx = %lf\n", map_info.mlx);
	printf("win = %lf\n", map_info.win);
	printf("\n");
}

void	print_player(t_map_info map_info)
{
	printf("\n");
	printf("========= player ==========\n");
	printf("pos_x=%lf pos_y=%lf\n", map_info.player.pos_x, map_info.player.pos_y);
	printf("dir_x=%lf dir_y=%lf\n", map_info.player.dir_x, map_info.player.dir_y);
	printf("plane_x=%lf plane_y=%lf\n", map_info.player.plane_x, map_info.player.plane_y);

}