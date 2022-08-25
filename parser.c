#include "cub3d.h"

// int	count_file_line(t_cub3d *game)
// {
// 	char	*line;
//{
// 	game->fd = open(game->filename, O_RDONLY);
// 	if (game->fd == -1)
// 	{
// 		ft_putstr_fd("Open failed.\n", 2);
// 		return (1);
// 	}
// 	else
// 	{
// 		printf("The file has been opened. FD number = %d.\n", game->fd);
// 		line = get_next_line(game->fd);
// 		if (!line)
// 		{
// 			ft_putstr_fd("Empty file.\n", 2);
// 			return (1);
// 		}
// 		while (line != NULL)
// 		{
// 			++game->map.nb_line;
// 			free(line);
// 			line = get_next_line(game->fd);
// 		}
// 		free(line);
// 		close(game->fd);
// 		printf("NBLINE=%ld\n", game->map.nb_line);
// 		return (0);
// 	}
// }

// int		filemap_to_map_array(t_cub3d *game)
// {
// 	size_t	i;
// 	char	*line;
//
// 	game->fd = open(game->filename, O_RDONLY);
// 	if (game->fd == -1)
// 	{
// 		ft_putstr_fd("Open failed.\n", 2);
// 		return (1);
// 	}
// 	game->file_content = malloc(sizeof(char *) * game->map.nb_line);
// 	if (!game->file_content)
// 	{
// 		ft_putstr_fd("Error with malloc of the map array\n", 2);
// 		return (1);
// 	}
// 	i = -1;
// 	line = get_next_line(game->fd);
// 	while (line != NULL)
// 	{
// 		game->file_content[++i] = line;
// 		line = get_next_line(game->fd);
// 	}
// 	close(game->fd);
// 	return (0);
// }

// void	fill_identifier(t_cub3d *game, char **identifier)
// {
// 	if (!ft_strcmp(identifier[0], "NO"))
// 	{
// 		game->map.identifier[0] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// 	else if (!ft_strcmp(identifier[0], "SO"))
// 	{
// 		game->map.identifier[1] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// 	else if (!ft_strcmp(identifier[0], "WE"))
// 	{
// 		game->map.identifier[2] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// 	else if (!ft_strcmp(identifier[0], "EA"))
// 	{
// 		game->map.identifier[3] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// 	else if (!ft_strcmp(identifier[0], "F"))
// 	{
// 		game->map.identifier[4] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// 	else if (!ft_strcmp(identifier[0], "C"))
// 	{
// 		game->map.identifier[5] = identifier[1];
// 		free(identifier[0]);
// 		free(identifier);
// 	}
// }

// void	check_identifier(t_cub3d *game)
// {
// 	size_t  i;
// 	char	**identifier;
// 	int		counter;

// 	counter = 0;
// 	i = 0;
// }

bool	map_start(t_cub3d *game)
{
	size_t	i;

	i = 0;
	while (game->file_line[i])
	{
		if (is_empty(game->file_line) || !is_valid_character(game->file_line[i]))
			return (false);
		++i;
	}
	return (true);
}

bool	is_valid_identifier(t_cub3d *game)
{

}

int		get_identifier(t_cub3d *game)
{
	char	*str;
	int		i;

	i = 0;
	while (game->file_line != NULL || !map_start(game))
	{
		if (!is_empty(game->file_line))
		{
			if (!is_valid_identifier(game->file_line))
				return (0);
		}
		free(game->file_line);
		game->file_line = get_next_line(game->fd);
	}
}

void	get_map(t_cub3d *game)
{

}

bool	is_parsed(t_cub3d *game)
{
	if (wrong_file(game))
		return (false);
	if (!get_identifier(game))
		return (false);
}

// int	ft_parse(t_cub3d *game)
// {
// 	int		ret;
// 	size_t	i;

// 	ret = 0;
// 	ret = count_file_line(game);
// 	if (ret != 0)
// 		return (ret);
// 	ret = filemap_to_map_array(game);
// 	if (ret != 0)
// 		return (ret);
// 	check_identifier(game);
// 	i = -1;
// 	while (++i < game->map.nb_line)
// 	{
// 		printf("map=%s", game->file_content[i]);
// 	}
// 	i = -1;
// 	while (++i < 6)
// 		printf("id=%s", game->map.identifier[i]);
// 	return (ret);
// }
