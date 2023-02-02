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

void	draw_updown(t_texture *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < DIS_H / 2)
	{
		j = 0;
		while (j < DIS_W)
			texture->buffer[i][j++] = texture->ceiling;
		i++;
	}
	while (i < DIS_H)
	{
		j = 0;
		while (j < DIS_W)
			texture->buffer[i][j++] = texture->floor;
		i++;
	}
}

void	draw_img(t_map_info *map_info, t_texture *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < DIS_H)
	{
		j = 0;
		while (j < DIS_W)
		{
			texture->data[i * DIS_W + j] = texture->buffer[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map_info->mlx, map_info->win, texture->img, 0, 0);
}
