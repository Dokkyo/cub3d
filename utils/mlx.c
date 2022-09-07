/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:36:44 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 16:36:45 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_mlx_instance(t_cub3d *game)
{
	game->mlx = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_cub3d(game, MLX_INIT);
}

void	get_mlx_window(t_cub3d *game)
{
	game->win = 0;
	game->win = mlx_new_window(game->mlx, WIN_SIZE, WIN_SIZE, "Cub3D");
	if (!game->win)
		exit_cub3d(game, MLX_WINDOW);
}

void	get_mlx_image(t_cub3d *game)
{
	game->images.cub3d.img = mlx_new_image(game->mlx, WIN_SIZE, WIN_SIZE);
	if (!game->images.cub3d.img)
		exit_cub3d(game, MLX_NEW_IMAGE);
	game->images.cub3d.addr = (int *)mlx_get_data_addr(
			game->images.cub3d.img,
			&game->images.cub3d.bpp,
			&game->images.cub3d.ll,
			&game->images.cub3d.endian);
}
