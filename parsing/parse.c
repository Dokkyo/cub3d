#include "../includes/cub3d.h"

static bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] > 32)
			return (false);
		i++;
	}
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

int	open_map(t_cub3d *game, char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			exit_cub3d(game, MAP_ENOENT);
		else if (errno == EACCES)
			exit_cub3d(game, MAP_EACCES);
		else
			exit_cub3d(game, MAP_OPEN);
	}
	return (fd);
}

static void	check_file_extension(t_cub3d *game, char *filename)
{
	size_t	len;

	len = 0;
	len = ft_strlen(filename);
	if (len < 5 || ft_strcmp(&filename[len - 4], ".cub"))
		exit_cub3d(game, MAP_EXTENSION);
}

void	parse(t_cub3d *game, char *filename)
{
	int		fd;
	int		map_start;
	char	*line;

	map_start = 0;
	check_file_extension(game, filename);
	fd = open_map(game, filename);
	while ((line = get_next_line(fd)))
	{
		++map_start;
		if (empty_line(line))
			;
		else if (!ft_strcspn(line, " 01"))
		{
			get_map(game, &fd, &line, map_start);
			break ;
		}
		else
		{
			get_identifiers(game, line);
		}
		free(line);
	}
	close(fd);
	check_identifiers(game);
	// check_map(game);
	get_mlx_window(game);
	get_mlx_image(game);
	raycasting(game);
}
