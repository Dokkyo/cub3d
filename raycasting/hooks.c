#include "../includes/cub3d.h"

static	int	render(t_cub3d *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->images.cub3d.img, 0, 0);
	return (0);
}

static int	key_hook(int key, t_cub3d *game)
{
	if (key == ESC)
		mlx_loop_end(game->mlx);
	if (key == W)
		move(game, game->player.dir);
	else if (key == S)
		move(game, rotate(game->player.dir, H));
	else if (key == A)
		move(game, rotate(game->player.dir, H / 2 * (-1)));
	else if (key == D)
		move(game, rotate(game->player.dir, H / 2));
	else if (key == RIGHT)
		rotate_player(&game->player, game->player.rot);
	else if (key == LEFT)
		rotate_player(&game->player, game->player.rot * (-1));
	else
		return (1);
	raycasting(game);
	return (0);
}

void	define_hooks(t_cub3d *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &key_hook, game);
	mlx_hook(game->win, ClientMessage, GCClipXOrigin, &mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, &render, (void *)game);
	mlx_loop(game->mlx);
}
