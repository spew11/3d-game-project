/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:12 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:28:13 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_updown(t_dis_size dis_size, t_texture *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < dis_size.height / 2)
	{
		j = 0;
		while (j < dis_size.width)
			texture->buffer[i][j++] = texture->ceil;
		i++;
	}
	while (i < dis_size.height)
	{
		j = 0;
		while (j < dis_size.width)
			texture->buffer[i][j++] = texture->floor;
		i++;
	}
}

void	draw_img(t_map_info *map_info, t_dis_size dis_size, t_texture *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < dis_size.height)
	{
		j = 0;
		while (j < dis_size.width)
		{
			texture->data[i * dis_size.width + j] = texture->buffer[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map_info->mlx, map_info->win, texture->img, 0, 0);
}
