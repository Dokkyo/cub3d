/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:33:38 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 15:47:08 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	line = get_next_line(fd);
	while (line != NULL)
	{
		++map_start;
		if (empty_line(line))
			;
		else if (!ft_strcspn(line, " 01"))
		{
			get_map(game, &fd, map_start);
			free(line);
			break ;
		}
		else
			get_identifiers(game, line);
		free(line);
		line = get_next_line(fd);
	}
	check_get_mlx_and_raytrace(game, &fd);
}
