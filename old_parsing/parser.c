#include "../includes/cub3d.h"

// bool	map_start(t_cub3d *game)
// {
// 	size_t	i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (is_empty(game->file_line))
// 		return (false);
// 	while (game->file_line[i])
// 	{
// 		if (is_valid_character(game->file_line[i]))
// 			++j;
// 		++i;
// 	}

// 	return (false);
// }

int		identifier(char *line, int i)
{
	if (!ft_strncmp(line + i, "NO ./", 5))
		return (1);
	else if (!ft_strncmp(line + i, "SO ./", 5))
		return (2);
	else if (!ft_strncmp(line + i, "WE ./", 5))
		return (3);
	else if (!ft_strncmp(line + i, "EA ./", 5))
		return (4);
	else if (!ft_strncmp(line + i, "F ", 3))
		return (5);
	else if (!ft_strncmp(line + i, "C ", 3))
		return (6);
	else
	{
		ft_putstr_fd("Wrong name identifier\n", 2);
		return (0);
	}
}

bool	get_color(t_cub3d *game, int i, int idx)
{
	(void)game;
	(void)i;
	(void)idx;
	printf("TO DO\n");
	return (true);
}

bool	get_texture(t_cub3d *game, int i, int idx)
{
	char	*texture;

	texture	= ft_strdup(game->file_line + i + 3);
	if (game->tex.textures[idx - 1] == NULL)
	{
		game->tex.textures[idx - 1] = mlx_xpm_file_to_image(game->mlx, texture, &game->tex.img_height, &game->tex.img_width);
		if (game->tex.textures[idx - 1] == NULL)
		{
			ft_putstr_fd("Texture reading has failed\n", 2);
			return (false);
		}
	}
	else
	{
		ft_putstr_fd("Double texture\n", 2);
		return (false);
	}
	return (true);
}

bool	is_valid_identifier(t_cub3d *game)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (ft_isspace(game->file_line[i]))
		++i;
	ret = identifier(game->file_line, i);
	if (ret > 0 && ret <= 4)
	{
		if (!get_texture(game, i, ret))
			return (false);
	}
	else if (ret == 5 || ret == 6)
	{
		if(!get_color(game, i, ret))
			return (false);
	}
	else
		return (false);
	return (true);
}

int		get_identifier(t_cub3d *game)
{
	while (game->file_line != NULL)
	{
		// if (map_start(game))
		// {
		// 	printf("line=%s\n", game->file_line);
		// 	break ;
		// }
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
