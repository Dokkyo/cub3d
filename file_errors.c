#include "cub3d.h"

bool	is_symbolic(t_cub3d *game)
{
	game->fd = open(game->filename, __O_NOFOLLOW);
	if (game->fd == -1)
		return (true);
	close(game->fd);
	return (false);
}

bool	is_directory(t_cub3d *game)
{
	game->fd = open(game->filename, __O_DIRECTORY);
	if (game->fd == -1)
		return (false);
	close(game->fd);
	return (true);
}

bool	is_open(t_cub3d *game)
{
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
		return (false);
	return (true);
}

int		wrong_file(t_cub3d *game)
{
	if (is_symbolic(game))
	{
		ft_putstr_fd("File is a symbolic link.\n", 2);
		return (1);
	}
	else if (is_directory(game))
	{
		ft_putstr_fd("Argument is a directory.\n", 2);
		return (1);
	}
	else if (!is_open(game))
		ft_putstr_fd("Open failed. Check errno.\n", 2);
	game->file_line = get_next_line(game->fd);
	if (!game->file_line)
	{
		ft_putstr_fd("Empty file\n", 2);
		return (1);
	}
	return (0);
}