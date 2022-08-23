#include "cub3d.h"

void	init(t_cub3d *game, char *filename)
{
	game->map.nb_line = 0;
	game->map.map = NULL;
	game->filename = filename;
	game->fd = -42;
	game->map.identifier[0] = NULL;
	game->map.identifier[1] = NULL;
	game->map.identifier[2] = NULL;
	game->map.identifier[3] = NULL;
	game->map.identifier[4] = NULL;
	game->map.identifier[5] = NULL;
}

void	free_map(t_cub3d *game)
{
	size_t	i;

	i = -1;
	while (++i < game->map.nb_line)
		free(game->map.map[i]);
	free(game->map.map);
}

int main(int ac, char **av)
{
	int len;
	int ret;
	t_cub3d game;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (av[1][len - 1] == 'b' && av[1][len - 2] == 'u' && av[1][len - 3] == 'c' && av[1][len - 4] == '.')
		{
			init(&game, av[1]);
			ret = ft_parse(&game);
			if (ret == 0)
			{
				//launch_game
			}
			if (game.map.map)
				 free_map(&game);
		}
		else
			ft_putstr_fd("Wrong file extension.", 2);
	}
	else
		ft_putstr_fd("Wrong arguments number.", 2);
}