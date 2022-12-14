/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:37:48 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/08 19:37:31 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_cub3d(t_cub3d *game)
{
	if (game)
	{
		if (game->map)
			free_2d_array(game->map);
		if (game->images.cub3d.img)
			mlx_destroy_image(game->mlx, game->images.cub3d.img);
		if (game->images.north.img)
			mlx_destroy_image(game->mlx, game->images.north.img);
		if (game->images.south.img)
			mlx_destroy_image(game->mlx, game->images.south.img);
		if (game->images.est.img)
			mlx_destroy_image(game->mlx, game->images.est.img);
		if (game->images.west.img)
			mlx_destroy_image(game->mlx, game->images.west.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
}

void	exit_cub3d(t_cub3d *game, int my_errno)
{
	destroy_cub3d(game);
	if (my_errno)
	{
		write(2, "Error : ", 8);
		write(2, game->my_strerror[my_errno],
			ft_strlen(game->my_strerror[my_errno]));
		write(2, "\n", 1);
	}
	exit(my_errno);
}
