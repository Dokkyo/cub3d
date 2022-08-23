#include "cub3d.h"

int	count_file_line(t_cub3d *game)
{
	char	*line;

	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Open failed.\n", 2);
		return (1);
	}
	else
	{
		// printf("The file has been opened. FD number = %d.\n", game->fd);
		line = get_next_line(game->fd);
		if (!line)
		{
			ft_putstr_fd("Empty file.\n", 2);
			return (1);
		}
		while (line != NULL)
		{
			++game->map.nb_line;
			free(line);
			line = get_next_line(game->fd);
		}
		free(line);
		close(game->fd);
		// printf("NBLINE=%ld\n", game->map.nb_line);
		return (0);
	}
}

int		filemap_to_map_array(t_cub3d *game)
{
	size_t	i;
	char	*line;

	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Open failed.\n", 2);
		return (1);
	}
	game->map.map = malloc(sizeof(char *) * game->map.nb_line);
	if (!game->map.map)
	{
		ft_putstr_fd("Error with malloc of the map array\n", 2);
		return (1);
	}
	i = -1;
	line = get_next_line(game->fd);
	while (line != NULL)
	{
		game->map.map[++i] = line;
		line = get_next_line(game->fd);
	}
	close(game->fd);
	return (0);
}


void	fill_identifier(t_cub3d *game, char **identifier)
{
	if (!ft_strcmp(identifier[0], "NO"))
	{
		game->map.identifier[0] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
	else if (!ft_strcmp(identifier[0], "SO"))
	{
		game->map.identifier[1] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
	else if (!ft_strcmp(identifier[0], "WE"))
	{
		game->map.identifier[2] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
	else if (!ft_strcmp(identifier[0], "EA"))
	{
		game->map.identifier[3] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
	else if (!ft_strcmp(identifier[0], "F"))
	{
		game->map.identifier[4] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
	else if (!ft_strcmp(identifier[0], "C"))
	{
		game->map.identifier[5] = identifier[1];
		free(identifier[0]);
		free(identifier);
	}
}

void	check_identifier(t_cub3d *game)
{
	size_t  i;
	char	**identifier;

	i = 0;
	while (1)
	{
		if (game->map.map[i][0] == ' ' || game->map.map[i][0] == '0' || game->map.map[i][0] == '1')
			break;
		if (game->map.map[i][0] > 31)
		{
			identifier = ft_split(game->map.map[i], ' ');
			fill_identifier(game, identifier);
		}
		++i;
	}
}

int	ft_parse(t_cub3d *game)
{
	int		ret;
	size_t	i;

	i = -1;
	ret = 1;
	ret = count_file_line(game);
	if (ret != 0)
		return (ret);
	ret = filemap_to_map_array(game);
	if (ret != 0)
		return (ret);
	check_identifier(game);
	while (++i < game->map.nb_line)
	{
		printf("map=%s", game->map.map[i]);
	}
	i = -1;
	while (++i < 6)
		printf("id=%s", game->map.identifier[i]);
	return (ret);
}
