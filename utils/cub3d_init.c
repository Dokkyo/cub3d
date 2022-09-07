/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:37:09 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 18:55:15 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_my_strerror_part_one(const char **my_strerror)
{
	my_strerror[MAP_MALLOC] = "map couldn't be malloced";
	my_strerror[MAP_ENOENT] = "map : no such file or directory";
	my_strerror[MAP_EACCES] = "map : permission denied";
	my_strerror[MAP_EISDIR] = "map is a directory";
	my_strerror[MAP_OPEN] = "cannot open map";
	my_strerror[MAP_READ] = "map read() failed";
	my_strerror[MAP_FT_SPLIT] = "get_map() : ft_split() failed";
	my_strerror[MAP_FT_STRNCAT] = "get_map(): ft_strncat() failed";
	my_strerror[MAP_EXTENSION] = "map is not a .cub file";
	my_strerror[MAP_NOT_CLOSE] = "map is not closed by walls";
	my_strerror[MAP_DUPLICATE] = "map splited by newline(s)";
	my_strerror[MAP_UNDEFINED] = "map contains undefined cells";
	my_strerror[MAP_LINE_FORMAT] = "line from .cub not well formatted";
	my_strerror[MAP_NO_CARDINAL] = "map contains no player";
	my_strerror[MAP_MULT_CARDINALS] = "map contains multiple players";
}

static void	init_my_strerror_part_two(const char **my_strerror)
{
	my_strerror[IMG_ADDR] = "mlx_get_data_addr() failed";
	my_strerror[MLX_INIT] = "mlx_init() failed";
	my_strerror[MLX_WINDOW] = "mlx_new_window() failed";
	my_strerror[MLX_NEW_IMAGE] = "mlx_new_image() failed";
	my_strerror[XPM_FORMAT] = "texture line not well formatted";
	my_strerror[XPM_SIZE] = "cub3d only accept 64 pixels large xpms";
	my_strerror[XPM_DUPLICATE] = "xpm duplicate";
	my_strerror[XPM_UNAVAILABLE] = "unable to open xpm file";
	my_strerror[XPM_MISSING] = "xpm missing";
	my_strerror[COLOR_FORMAT] = "color format incorrect";
	my_strerror[COLOR_MALLOC] = "get_color() : malloc() failed";
	my_strerror[COLOR_RANGE] = "color outside of range [0;255]";
	my_strerror[COLOR_MISSING] = "floor or ceiling color missing";
	my_strerror[COLOR_DUPLICATE] = "color duplicate";
	my_strerror[MAIN_ARG] = "cub3d only needs one argument";
}

static void	init_player(t_player *player)
{
	player->fov = FOV * M_PI / 180.0;
	player->rot = ROTATION_UNIT * M_PI / 180.0;
	player->mov = MOVEMENT_UNIT;
}

void	init_cub3d(t_cub3d *game, char *filename)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->colors.floor.parsed = 0;
	game->colors.ceiling.parsed = 0;
	game->images.est.img = 0;
	game->images.west.img = 0;
	game->images.north.img = 0;
	game->images.south.img = 0;
	game->images.cub3d.img = 0;
	game->filename = filename;
	init_player(&game->player);
	init_my_strerror_part_one(game->my_strerror);
	init_my_strerror_part_two(game->my_strerror);
	get_mlx_instance(game);
}
