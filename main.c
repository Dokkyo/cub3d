#include "cub3d.h"

void	init(t_cub3d *game, char *filename)
{
	game->map.nb_line = 0;
	game->file_line = NULL;
	game->filename = filename;
	game->fd = -42;
	game->map.identifier[0] = NULL;
	game->map.identifier[1] = NULL;
	game->map.identifier[2] = NULL;
	game->map.identifier[3] = NULL;
	game->map.identifier[4] = NULL;
	game->map.identifier[5] = NULL;
}


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// int len;
	// int ret;
	// t_cub3d game;

	// if (ac == 2)
	// {
	// 	len = ft_strlen(av[1]);
	// 	if (av[1][len - 1] == 'b' && av[1][len - 2] == 'u' && av[1][len - 3] == 'c' && av[1][len - 4] == '.')
	// 	{
	// 		init(&game, av[1]);
	// 		if (is_parsed(game))
	// 		{
	// 			launch_game
	// 		}
	// 	}
	// 	else
	// 		ft_putstr_fd("Wrong file extension.", 2);
	// }
	// else
	// 	ft_putstr_fd("Wrong arguments number.", 2);
}
