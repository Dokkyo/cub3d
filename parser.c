#include "cub3d.h"

// void	fill_identifier(t_cub3d *game, int i)
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
	printf("It start !\n");
	return (true);
}

bool	is_valid_identifier(t_cub3d *game)
{
	(void)game;
	size_t	i;

	i = 0;
	while (game->file_line[i])
	{
		while (ft_isspace(game->file_line[i]))
			++i;
		++i;
	}

	return (true);
}

int		get_identifier(t_cub3d *game)
{
	//char	*str;

	while (game->file_line != NULL && !map_start(game))
	{
		printf("line=%s\n", game->file_line);
		if (!is_empty(game->file_line))
		{
			if (!is_valid_identifier(game))
				return (0);
		}
		free(game->file_line);
		game->file_line = get_next_line(game->fd);
	}
	printf("line=%s\n", game->file_line);
	return (1);
}

void	get_map(t_cub3d *game)
{
	(void)game;
}

bool	is_parsed(t_cub3d *game)
{
	if (wrong_file(game))
		return (false);
	if (!get_identifier(game))
		return (false);

	return (true);
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
