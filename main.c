#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	game;

	init_cub3d(&game, av[1]);
	if (ac == 2)
	{
		parse(&game, av[1]);
		define_hooks(&game);
		exit_cub3d(&game, 0);
	}
	else
		exit_cub3d(&game, MAIN_ARG);
	return (0);
}