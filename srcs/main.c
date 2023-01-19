/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:04 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/19 17:12:28 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	int			fd;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	init_map_info(&map_info, fd);
	// printf("dis_size = %d %d\n", map_info.dis_size.width, map_info.dis_size.height);
	// for (int i = 0; i < 4; i++)
	// printf("wall[%d] = %s\n", i, map_info.texture.walls[i]);
	// printf("item = %s\n", map_info.texture.item);
	// for (int i = 0; i < 3; i++)
	// 	printf("floor[%d] = %d\n", i, map_info.texture.floor[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("ceil[%d] = %d\n", i, map_info.texture.ceil[i]);
	// printf("==== map_line ====\n%s\n", map_info.map_line);
	// printf("\n");
	// for (int i = 0; map_info.map[i]; i++)
	// 	printf("%s\n", map_info.map[i]);
	// printf("\n");
	
	// printf("==== texture ====\n");

	
	// printf("Map size : height = %d, ", map_info.height);
	// for (int i = 0; i < map_info.height; i++) {
	// 	printf("%d ", map_info.widths[i]);
	// }
	// printf("\n");
	//check_map(&map_info);
	// system("leaks cub3D");
	// map_info.mlx = mlx_init();
	// map_info.win = mlx_new_window(map_info.mlx, \
	map_info.width * 64, map_info.height * 64, "taehyeong's game");
	// map_info.img = set_img(map_info.mlx);
	// draw_map(map_info);
	// mlx_hook(map_info.win, KEY_RELEASE, 0, &key_press, &map_info);
	// mlx_hook(map_info.win, KEY_EXIT, 0, &exit_game, &map_info);
	// mlx_loop(map_info.mlx);
}
