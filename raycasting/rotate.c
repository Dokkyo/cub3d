#include "../includes/cub3d.h"

double	rotate(double ray, double angle)
{
	double	ret;

	ret = ray + angle;
	while (ret >= 2 * H)
		ret -= 2 * H;
	while (ret < 0)
		ret += 2 * H;
	return (ret);
}

void	rotate_player(t_player *player, double angle)
{
	player->dir = rotate(player->dir, angle);
}
