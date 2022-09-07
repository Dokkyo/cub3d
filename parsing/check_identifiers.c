/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:39:04 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 16:19:35 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_color_digits(char *tmp)
{
	if (ft_isin(tmp, BASE_DEC_SPACE))
		return (true);
	else
		return (false);
}

bool	check_color_range(char *tmp)
{
	int	color;

	color = ft_atoi(tmp);
	if (color < 0 || color > 255)
		return (false);
	return (true);
}

static void	check_identifiers(t_cub3d *game)
{
	if (!game->images.est.img
		|| !game->images.west.img
		|| !game->images.north.img
		|| !game->images.south.img)
		exit_cub3d(game, XPM_MISSING);
	if (game->images.est.ll != 256
		|| game->images.west.ll != 256
		|| game->images.north.ll != 256
		|| game->images.south.ll != 256)
		exit_cub3d(game, XPM_SIZE);
	if (!game->colors.floor.parsed
		|| !game->colors.ceiling.parsed)
		exit_cub3d(game, COLOR_MISSING);
}

void	check_get_mlx_and_raytrace(t_cub3d *game, int *fd)
{
	close(*fd);
	check_identifiers(game);
	check_map(game);
	get_mlx_window(game);
	get_mlx_image(game);
	raycasting(game);
}