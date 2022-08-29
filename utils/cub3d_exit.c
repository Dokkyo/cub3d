#include "../includes/cub3d.h"

static void	destroy_cub3d(t_cub3d *game)
{
	if (game)
	{
		/*
			free ce qu'on doit free.
			if (x)
				free(x);
			[...]
		*/
	}
}

void	exit_cub3d(t_cub3d *game, int my_errno)
{
	destroy_cub3d(game);
	if (my_errno)
	{
		write(2, "Error : ", 8);
		write(2, game->my_strerror[my_errno],
			ft_strlen(game->my_strerror[my_errno]));
		write(2, "\n", 1);
	}
	exit(my_errno);
}
