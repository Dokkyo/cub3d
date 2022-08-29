#include "cub3d.h"

// void	init(t_cub3d *game, char *filename)
// {
// 	game->map.nb_line = 0;
// 	game->file_line = NULL;
// 	game->filename = filename;
// 	game->fd = -42;
// 	game->tex.textures[0] = NULL;
// 	game->tex.textures[1] = NULL;
// 	game->tex.textures[2] = NULL;
// 	game->tex.textures[3] = NULL;
// 	game->tex.img_height = 150;
// 	game->tex.img_height = 150;
// 	game->mlx = mlx_init();
// }

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;

// 	int len;
// 	//int ret;
// 	t_cub3d game;

// 	if (ac == 2)
// 	{
// 		len = ft_strlen(av[1]);
// 		if (ft_strcmp(av[1][len - 4], ".cub"))
// 		{
// 			init(&game, av[1]);
// 			if (is_parsed(&game))
// 			{
// 				printf("Launch game\n");
// 			}
// 		}
// 		else
// 			ft_putstr_fd("Wrong file extension.", 2);
// 	}
// 	else
// 		ft_putstr_fd("Wrong arguments number.", 2);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_cub3d	game;

	init_cub3d(&game);
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
