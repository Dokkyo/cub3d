#include "../includes/cub3d.h"

/*
**	Recoit la struct principale, le fd du .cub et l'adresse du retour de gnl a partir du moment ou on croise un "space01"
**	Chaque ligne est stocke dans un char** de la struct map, ce char** sera ensuite parse par une autrre fct.
*/
void	get_map(t_cub3d game, int fd, char **line)
{
	(void)game;
	(void)fd;
	printf("MAP START=%s\n", *line);
}
