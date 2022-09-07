#include "../includes/cub3d.h"

/*
**	Recoit la struct principale, le fd du .cub et l'adresse du retour de gnl
**	a partir du moment ou on croise un "space01"
**	Chaque ligne est stocke dans un char** de la struct map, ce char** sera
**	ensuite parse par une autrre fct.
*/
void	get_map(t_cub3d *game, int *fd, char **line, int map_start)
{
	int		map_end;
	char	*trash;
	int		i;
	int		j;

	(void)line;
	map_end = map_start;
	trash = get_next_line(*fd);
	while (trash > 0)
		++map_end;
	close(*fd);
	game->map = malloc(sizeof(char *) * (map_end - map_start + 1));
	if (!game->map)
		exit_cub3d(game, MAP_MALLOC);
	*fd = open_map(game, game->filename);
	i = -1;
	while (++i < map_start - 1)
		get_next_line(*fd);
	j = 0;
	while (i <= map_end)
	{
		game->map[j] = get_next_line(*fd);
		++j;
		++i;
	}
}
