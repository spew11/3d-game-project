#include "cub3D.h"

int	img_init(t_texture *texture)
{
	int	i;
	int	j;

	// i = 0;
	// while (i < TEX_W)
	// {
	// 	j = 0;
	// 	while (j < SCWIDTH)
	// 		img->buffer[i][j++] = 0;
	// 	i++;
	// }
	// texture->walls = (int **)malloc(sizeof(int *) * 5);
	// if (!img->arr_img)
		// ft_exit("image_init malloc error");
	i = 0;
	while (i < 4)					//		WALLS IMAGE MALLOC
	{
		texture->walls_img[i] = (int *)malloc(sizeof(int) * TEX_W * TEX_H);
		if (!texture->walls_img[i])
			exit_error("image malloc error\n");
		ft_memset(texture->walls_img[i], 0, (sizeof(int) * TEX_W * TEX_H));
		i++;
	}
	texture->item_img = (int *)malloc(sizeof(int) * TEX_W * TEX_H);
	ft_memset(texture->item_img, 0, (sizeof(int) * TEX_W * TEX_H));
	return (0);
}

// void	fill_arr_img(t_map_info *map_info, int i)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < info->img.h)
// 	{
// 		x = 0;
// 		while (x < info->img.w)
// 		{
// 			info->img.arr_img[i][info->img.w * y + x] = \
// 				info->img.data[info->img.h * y + x];
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	set_walls_img(t_texture *texture, int i)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < TEX_H)
	{
		x = 0;
		while (x < TEX_W)
		{
			texture->walls_img[i][TEX_W * y + x] = texture->data[TEX_W * y + x];
			x++;
		}
		y++;
	}
}

void	parse_img(t_map_info *map_info, t_texture *texture)
{
	int		i;
	char	*tmp;
	void	*img;
	int		w;
	int		h;

	img_init(texture);
	i = 0;
	while (i < 4)
	{
		if (i == NO)
			tmp = texture->walls[i];
		else if (i == WE)
			tmp = texture->walls[i];
		else if (i == SO)
			tmp = texture->walls[i];
		else
			tmp = texture->walls[i];
		texture->img = mlx_xpm_file_to_image(map_info->mlx, tmp, &w, &h);
		texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp, &texture->size_line, &texture->endian);
		set_walls_img(texture, i);
		mlx_destroy_image(map_info->mlx, texture->img);
		i++;
	}
}

// void	image_load(t_info *info)
// {
// 	char	*path;
// 	int		i;

// 	i = 1;
// 	while (i < 5)
// 	{
// 		if (i == E)
// 			path = info->map.ea_path;
// 		else if (i == W)
// 			path = info->map.we_path;
// 		else if (i == S)
// 			path = info->map.so_path;
// 		else
// 			path = info->map.no_path;
// 		printf("%d\n", info->img.h);
// 		info->img.img = \
// 			mlx_xpm_file_to_image(info->mlx, path, &info->img.w, &info->img.h);
// 		printf("%d\n", info->img.h);
// 		if (info->img.w != TEXWIDTH || info->img.h != TEXHEIGHT
// 			|| info->img.img == NULL)
// 			ft_exit("image_load xpm file error");
// 		info->img.data = (int *)mlx_get_data_addr(info->img.img, \
// 					&info->img.bpp, &info->img.line_size, &info->img.endian);
// 		fill_arr_img(info, i);
// 		mlx_destroy_image(info->mlx, info->img.img);
// 		i++;
// 	}
// }
