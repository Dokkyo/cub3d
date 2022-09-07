/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:32:35 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 15:33:31 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	go_to_map_end(int *fd, int *map_end)
{
	char	*trash;

	trash = get_next_line(*fd);
	while (trash > 0)
	{
		++(*map_end);
		free(trash);
		trash = get_next_line(*fd);
	}
}

/*
**	Recoit la struct principale, le fd du .cub et l'adresse du retour
**	de gnl a partir du moment ou on croise un "space01"
**	Chaque ligne est stocke dans un char** de la struct map, ce char**
**	sera ensuite parse par une autrre fct.
*/
void	get_map(t_cub3d *game, int *fd, int map_start)
{
	int		map_end;
	int		i;
	int		j;
	char	*trash;

	map_end = map_start;
	go_to_map_end(fd, &map_end);
	close(*fd);
	game->map = malloc(sizeof(char *) * (map_end - map_start + 1));
	if (!game->map)
		exit_cub3d(game, MAP_MALLOC);
	*fd = open_map(game, game->filename);
	i = -1;
	while (++i < map_start - 1)
	{
		trash = get_next_line(*fd);
		free(trash);
	}
	j = 0;
	while (i <= map_end)
	{
		game->map[j] = get_next_line(*fd);
		++j;
		++i;
	}
}
