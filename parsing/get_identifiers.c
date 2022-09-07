/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:39:04 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 15:55:43 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_texture(t_cub3d *game, t_image *image, char *line)
{
	int		x;
	int		y;
	char	*texture;

	if (image->img)
		exit_cub3d(game, XPM_DUPLICATE);
	if (*line != ' ')
		exit_cub3d(game, XPM_FORMAT);
	skip_spaces(&line);
	texture = ft_strdup(line);
	image->img = mlx_xpm_file_to_image(game->mlx, texture, &x, &y);
	free(texture);
	if (image->img == NULL)
		exit_cub3d(game, XPM_UNAVAILABLE);
	image->addr = 0;
	image->addr = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->ll, &image->endian);
	if (image->addr == 0)
		exit_cub3d(game, IMG_ADDR);
}

static void	get_color(t_cub3d *game, t_color *color, char *line)
{
	char	**tmp;
	int		i;

	if (color->parsed)
		exit_cub3d(game, COLOR_DUPLICATE);
	skip_spaces(&line);
	tmp = 0;
	tmp = ft_split(line, ',');
	if (!tmp)
		exit_cub3d(game, COLOR_MALLOC);
	if (length_2d_array(tmp) != 3)
		exit_cub3d(game, COLOR_FORMAT);
	i = 0;
	while (i < 3)
	{
		if (check_color_digits(tmp[i]) == false)
		{
			free_2d_array(tmp);
			exit_cub3d(game, COLOR_FORMAT);
		}
		if (check_color_range(tmp[i]) == false)
		{
			free_2d_array(tmp);
			exit_cub3d(game, COLOR_RANGE);
		}
		i++;
	}
	color->r = (unsigned char)ft_atoi(tmp[0]);
	color->g = (unsigned char)ft_atoi(tmp[1]);
	color->b = (unsigned char)ft_atoi(tmp[2]);
	color->color = (color->r << 16 | color->g << 8 | color->b);
	color->parsed = 1;
	free_2d_array(tmp);
}

void	get_identifiers(t_cub3d *game, char *line)
{
	if (line[0] == 'F')
		get_color(game, &game->colors.floor, line + 1);
	else if (line[0] == 'C')
		get_color(game, &game->colors.ceiling, line + 1);
	else if (line[0] == 'N' && line[1] == 'O')
		get_texture(game, &game->images.north, line + 2);
	else if (line[0] == 'W' && line[1] == 'E')
		get_texture(game, &game->images.west, line + 2);
	else if (line[0] == 'E' && line[1] == 'A')
		get_texture(game, &game->images.est, line + 2);
	else if (line[0] == 'S' && line[1] == 'O')
		get_texture(game, &game->images.south, line + 2);
	else
		exit_cub3d(game, MAP_LINE_FORMAT);
}
