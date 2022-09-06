/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:09:27 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/06 15:09:28 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_undefined_cells(t_cub3d *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strcspn2(game->map[i], " 01NSEW\n"))
			exit_cub3d(game, MAP_UNDEFINED);
		i++;
	}
}

static void	check_cardinal(t_cub3d *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = elems_index(map[y], "NSEW");
		if (x > -1)
		{
			get_player_game(&game->player, x, y, map[y][x]);
			if (elems_index(map[y] + x + 1, "NSEW") > -1)
				exit_cub3d(game, MAP_MULT_CARDINALS);
			while (map[++y])
			{
				if (elems_index(map[y], "NSEW") > -1)
					exit_cub3d(game, MAP_MULT_CARDINALS);
			}
			return ;
		}
		y++;
	}
	exit_cub3d(game, MAP_NO_CARDINAL);
}

static void	check_map_closed(t_cub3d *game, char **map)
{
	int	i;
	int	j;

	i = length_2d_array(map);
	if (ft_strcspn2(map[0], " 1\n"))
		exit_cub3d(game, MAP_NOT_CLOSE);
	if (ft_strcspn2(map[i - 1], " 1\n"))
		exit_cub3d(game, MAP_NOT_CLOSE);
	while (--i)
	{
		j = ft_strlen(map[i]) - 1;
		if (elem_index(" 1\n", map[i][0]) == -1
			|| elem_index(" 1\n", map[i][j]) == -1)
			exit_cub3d(game, MAP_NOT_CLOSE);
		while (--j)
		{
			if (map[i][j] == '0')
				check_space(game, map, i, j);
		}
	}
}

void	get_player_game(t_player *player, int x, int y, char c)
{
	player->map.x = x;
	player->map.y = y;
	player->pos.x = (double)CUB_SIZE * ((double)x + 1.0 / 3.0);
	player->pos.y = (double)CUB_SIZE * ((double)y + 1.0 / 3.0);
	if (c == 'W')
		player->dir = M_PI;
	else if (c == 'S')
		player->dir = M_PI / 2;
	else if (c == 'N')
		player->dir = 3 * M_PI / 2;
	else
		player->dir = 0;
}

/*
**	Recoit la struct principale
**	Check si la map est bien formate (ne s'occupe pas de checker
**	le fichier .cub ni de checker si les identiffiers sont correct)
**	Dans la struct map, il est cense avoir un char** contenant
**	chaques lignes a partir du debut de la map "space01" jusqu'a EOF
*/
void	check_map(t_cub3d *game)
{
	if (game->map)
	{
		check_undefined_cells(game);
		check_cardinal(game, game->map);
		check_map_closed(game, game->map);
	}
}
