#include "../includes/cub3d.h"

static t_double_vector	get_delta_move(double dir, double movement_unit)
{
	t_double_vector	delta;

	if (dir < 0.5 * H)
	{
		delta.x = cos(dir) * movement_unit;
		delta.y = cos(0.5 * H - dir) * movement_unit;
	}
	else if (dir < H)
	{
		delta.x = cos(H - dir) * MOVEMENT_UNIT;
		delta.y = cos(dir - 0.5 * H) * MOVEMENT_UNIT;
	}
	else if (dir < 1.5 * H)
	{
		delta.x = cos(dir - H) * movement_unit;
		delta.y = cos(1.5 * H - dir) * movement_unit;
	}
	else
	{
		delta.x = cos(2.0 * H - dir) * movement_unit;
		delta.y = cos(dir - 1.5 * H) * movement_unit;
	}
	return (delta);
}

static inline double	get_move_dist(t_double_vector delta)
{
	return (sqrt(pow(delta.x, 2) + pow(delta.y, 2)));
}

void	move(t_cub3d *game, double dir)
{
	double			dist;
	double			wall;
	t_int_vector	step;
	t_double_vector	delta;

	step = get_step(dir);
	delta = get_delta_move(dir, game->player.mov);
	dist = get_move_dist(delta);
	game->ray.angle = dir;
	dda(game);
	wall = fmin(game->ray.dist.x, game->ray.dist.y);
	if (dist < wall
		&& game->map[(int)((game->player.pos.y + delta.y * step.y) / CUB_SIZE)]
		[(int)((game->player.pos.x + delta.x * step.x) / CUB_SIZE)] != '1')
	{
		game->player.pos.x += delta.x * step.x;
		game->player.pos.y += delta.y * step.y;
		game->player.map.x = (int)(game->player.pos.x / CUB_SIZE);
		game->player.map.y = (int)(game->player.pos.y / CUB_SIZE);
	}
}
