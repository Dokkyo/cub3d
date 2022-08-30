#include "../includes/cub3d.h"

double	rotate(double ray, double angle)
{
	double	ret;

	ret = ray + angle;
	while (ret >= 2 * M_PI)
		ret -= 2 * M_PI;
	while (ret < 0)
		ret += 2 * M_PI;
	return (ret);
}

void	rotate_player(t_player *player, double angle)
{
	player->dir = rotate(player->dir, angle);
}
