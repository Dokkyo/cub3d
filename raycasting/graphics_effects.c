#include "../includes/cub3d.h"

static void	get_wall_column(t_cub3d *game)
{
	double			col;
	double			angle;
	t_double_vector	pos;
	t_image			*texture;

	angle = game->ray.angle;
	texture = game->wall.texture;
	pos = game->player.pos;
	if (texture == &game->images.est && angle < 0.5 * H)
		col = pos.y + sin(angle) * game->ray.dist.x;
	else if (texture == &game->images.est && angle > 1.5 * H)
		col = pos.y - sin(2 * H - angle) * game->ray.dist.x;
	else if (texture == &game->images.west && angle < H)
		col = pos.y + sin(H - angle) * game->ray.dist.x;
	else if (texture == &game->images.west && angle > H)
		col = pos.y - sin(angle - H) * game->ray.dist.x;
	else if (texture == &game->images.north && angle < H * 1.5)
		col = pos.x - sin(H * 1.5 - angle) * game->ray.dist.y;
	else if (texture == &game->images.north && angle > H * 1.5)
		col = pos.x + sin(angle - 1.5 * H) * game->ray.dist.y;
	else if (texture == &game->images.south && angle < H * 0.5)
		col = pos.x + sin(0.5 * H - angle) * game->ray.dist.y;
	else
		col = pos.x - sin(angle - 0.5 * H) * game->ray.dist.y;
	game->wall.column = (int)(col) % CUB_SIZE;
}

static void	get_wall_dist(t_cub3d *game)
{
	double	fisheye_corrector;

	fisheye_corrector = cos(game->player.dir - game->ray.angle);
	game->wall.dist = fmin(game->ray.dist.x, game->ray.dist.y)
		* fisheye_corrector;
}

static void	get_wall_texture(t_cub3d *game)
{
	if (game->ray.dist.x < game->ray.dist.y)
	{
		if (game->ray.angle > 0.5 * H && game->ray.angle < 1.5 * H)
			game->wall.texture = &game->images.west;
		else
			game->wall.texture = &game->images.est;
	}
	else
	{
		if (game->ray.angle > 0 && game->ray.angle < H)
			game->wall.texture = &game->images.south;
		else
			game->wall.texture = &game->images.north;
	}
}

static void	get_wall_height(t_cub3d *game)
{
	game->wall.height = (int)((double)CUB_SIZE / 2 / game->wall.dist
			* (double)WIN_SIZE / tan(game->player.fov / 2));
	if (game->wall.height > WIN_SIZE)
	{
		game->wall.lo = WIN_SIZE / 2 - game->wall.height / 2;
		game->wall.hi = WIN_SIZE;
	}
	else
	{
		game->wall.lo = WIN_SIZE / 2 - game->wall.height / 2;
		game->wall.hi = WIN_SIZE / 2 + game->wall.height / 2;
	}
}

void	textured_column_to_image(t_cub3d *game)
{
	int	row;
	int	color;

	get_wall_dist(game);
	get_wall_texture(game);
	get_wall_height(game);
	get_wall_column(game);
	row = 0;
	while (row < game->wall.lo)
	{
		pixel_to_image(&game->images.cub3d, game->ray.column, row++,
			game->colors.ceiling.color);
	}
	while (row < game->wall.hi)
	{
		color = get_image_pixel_color(game->wall.texture, game->wall.column,
				(row - game->wall.lo) * CUB_SIZE / game->wall.height);
		pixel_to_image(&game->images.cub3d, game->ray.column, row++, color);
	}
	while (row < WIN_SIZE)
	{
		pixel_to_image(&game->images.cub3d, game->ray.column, row++,
			game->colors.floor.color);
	}
}
