/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:55 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/01 19:37:25 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	img_init(t_texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
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

void	parse_img2(t_texture *texture, int i, char **wall_path)
{
	if (i == NO)
		*wall_path = texture->walls[i];
	else if (i == WE)
		*wall_path = texture->walls[i];
	else if (i == SO)
		*wall_path = texture->walls[i];
	else if (i == EA)
		*wall_path = texture->walls[i];
	return ;
}

void	parse_img(t_map_info *map_info, t_texture *texture)
{
	int		i;
	char	*wall_path;
	int		w;
	int		h;

	img_init(texture);
	i = 0;
	while (i < 4)
	{
		parse_img2(texture, i, &wall_path);
		texture->img = mlx_xpm_file_to_image(map_info->mlx, wall_path, &w, &h);
		if (!texture->img)
			exit_error("image error\n");
		if (w != TEX_W || h != TEX_H)
			exit_error("weird texture size\n");
		texture->data = (int *)mlx_get_data_addr(texture->img, \
		&texture->bpp, &texture->size_line, &texture->endian);
		set_walls_img(texture, i);
		mlx_destroy_image(map_info->mlx, texture->img);
		i++;
	}
}
