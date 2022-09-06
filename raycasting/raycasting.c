/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:10:32 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/06 15:10:32 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_int_vector	get_step(double ray)
{
	t_int_vector	step;

	if (ray < 0.5 * M_PI)
	{
		step.x = 1;
		step.y = 1;
	}
	else if (ray < M_PI)
	{
		step.x = -1;
		step.y = 1;
	}
	else if (ray < 1.5 * M_PI)
	{
		step.x = -1;
		step.y = -1;
	}
	else
	{
		step.x = 1;
		step.y = -1;
	}
	return (step);
}

static t_double_vector	get_delta_dist(double ray)
{
	t_double_vector	delta_dist;

	if (ray < 0.5 * M_PI)
	{
		delta_dist.x = CUB_SIZE / cos(ray);
		delta_dist.y = CUB_SIZE / cos(0.5 * M_PI - ray);
	}
	else if (ray < M_PI)
	{
		delta_dist.x = CUB_SIZE / cos(M_PI - ray);
		delta_dist.y = CUB_SIZE / cos(ray - 0.5 * M_PI);
	}
	else if (ray < 1.5 * M_PI)
	{
		delta_dist.x = CUB_SIZE / cos(ray - M_PI);
		delta_dist.y = CUB_SIZE / cos(1.5 * M_PI - ray);
	}
	else
	{
		delta_dist.x = CUB_SIZE / cos(2.0 * M_PI - ray);
		delta_dist.y = CUB_SIZE / cos(ray - 1.5 * M_PI);
	}
	return (delta_dist);
}

static t_double_vector	init_ray_dist(t_int_vector map, t_double_vector pos,
										double ray)
{
	t_double_vector	dist;

	if (ray < 0.5 * M_PI)
	{
		dist.y = ((map.y + 1) * CUB_SIZE - pos.y) / cos(0.5 * M_PI - ray);
		dist.x = ((map.x + 1) * CUB_SIZE - pos.x) / cos(ray);
	}
	else if (ray < M_PI)
	{
		dist.y = ((map.y + 1) * CUB_SIZE - pos.y) / cos(ray - 0.5 * M_PI);
		dist.x = (pos.x - map.x * CUB_SIZE) / cos(M_PI - ray);
	}
	else if (ray < 1.5 * M_PI)
	{
		dist.y = (pos.y - map.y * CUB_SIZE) / cos(1.5 * M_PI - ray);
		dist.x = (pos.x - map.x * CUB_SIZE) / cos(ray - M_PI);
	}
	else
	{
		dist.y = (pos.y - map.y * CUB_SIZE) / cos(ray - 1.5 * M_PI);
		dist.x = ((map.x + 1) * CUB_SIZE - pos.x) / cos(2.0 * M_PI - ray);
	}
	return (dist);
}

void	dda(t_cub3d *game)
{
	game->ray.map = game->player.map;
	game->ray.step = get_step(game->ray.angle);
	game->ray.delta = get_delta_dist(game->ray.angle);
	game->ray.dist = init_ray_dist(
			game->player.map,
			game->player.pos,
			game->ray.angle);
	while (1)
	{
		if (game->ray.dist.x < game->ray.dist.y)
		{
			game->ray.map.x += game->ray.step.x;
			if (game->map[game->ray.map.y][game->ray.map.x] == '1')
				break ;
			game->ray.dist.x += game->ray.delta.x;
		}
		else
		{
			game->ray.map.y += game->ray.step.y;
			if (game->map[game->ray.map.y][game->ray.map.x] == '1')
				break ;
			game->ray.dist.y += game->ray.delta.y;
		}
	}
}

void	raycasting(t_cub3d *game)
{
	game->ray.rot = (double)(game->player.fov / (double)WIN_SIZE);
	game->ray.angle = rotate(game->player.dir, game->player.fov / 2.0 * (-1.0));
	game->ray.column = 0;
	while (game->ray.column < WIN_SIZE)
	{
		dda(game);
		textured_column_to_image(game);
		game->ray.angle = rotate(game->ray.angle, game->ray.rot);
		game->ray.column++;
	}
}
