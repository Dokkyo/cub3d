#include "../includes/cub3d.h"

static void	get_texture(t_cub3d *game, t_image *image, char *line)
{
	int		x;
	int		y;

	if (image->img)
		exit_cub3d(game, XPM_DUPLICATE);
	if (*line != ' ')
		exit_cub3d(game, XPM_FORMAT);
	skip_spaces(&line);
	image->img = mlx_xpm_file_to_image(game->mlx, line, &x, &y);
	if (image->img == 0)
		exit_cub3d(game, XPM_UNAVAILABLE);
	image->addr = 0;
	image->addr = (int *)mlx_get_data_addr(
			image->img, &image->bpp, &image->ll, &image->endian);
	if (image->addr == 0)
		exit_cub3d(game, IMG_ADDR);
}

static void	check_color_digits(t_cub3d *game, char **tmp, int i)
{
	if (ft_strcspn(tmp[i], BASE_DEC))
	{
		free_2d_array(tmp);
		exit_cub3d(game, COLOR_FORMAT);
	}
}

static void	check_color_range(t_cub3d *game, char **tmp, int i)
{
	int	color;

	color = ft_atoi(tmp[i]);
	if (color < 0 || color > 255)
	{
		free_2d_array(tmp);
		exit_cub3d(game, COLOR_RANGE);
	}
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
		check_color_digits(game, tmp, i);
		check_color_range(game, tmp, i);
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
	if (*line == 'F')
		get_color(game, &game->colors.floor, line + 1);
	else if (*line == 'C')
		get_color(game, &game->colors.ceiling, line + 1);
	else if (*line == 'N' && line[1] == 'O')
		get_texture(game, &game->images.north, line + 2);
	else if (*line == 'W' && line[1] == 'E')
		get_texture(game, &game->images.west, line + 2);
	else if (*line == 'E' && line[1] == 'A')
		get_texture(game, &game->images.est, line + 2);
	else if (*line == 'S' && line[1] == 'O')
		get_texture(game, &game->images.south, line + 2);
	else
		exit_cub3d(game, MAP_LINE_FORMAT);
}