/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:26:04 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:26:07 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Type like ./cub3D <map name>\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 1) != 0)
		exit_error("File type should be \".cub\"\n");
}

void	check_fd(int fd)
{
	if (fd < 0)
		exit_error("Failed to open file\n");
}
