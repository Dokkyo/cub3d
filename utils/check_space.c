/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:11:31 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/06 15:11:32 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*get_lower_cell(char **map, int row, size_t col)
{
	if (col >= ft_strlen(map[row + 1]))
		return (0);
	return (&map[row + 1][col]);
}

static char	*get_upper_cell(char **map, int row, size_t col)
{
	if (col >= ft_strlen(map[row - 1]))
		return (0);
	return (&map[row - 1][col]);
}

static char	*get_right_cell(char **map, int row, size_t col)
{
	if (col == ft_strlen(map[row]) - 1)
		return (0);
	return (&map[row][col + 1]);
}

static char	*get_left_cell(char **map, int row, int col)
{
	if (!col)
		return (0);
	return (&map[row][col - 1]);
}

void	check_space(t_cub3d *game, char **map, int row, int col)
{
	char	*tmp;

	tmp = get_upper_cell(map, row, col);
	if (!tmp || *tmp == ' ')
		exit_cub3d(game, MAP_NOT_CLOSE);
	tmp = get_lower_cell(map, row, col);
	if (!tmp || *tmp == ' ')
		exit_cub3d(game, MAP_NOT_CLOSE);
	tmp = get_right_cell(map, row, col);
	if (!tmp || *tmp == ' ')
		exit_cub3d(game, MAP_NOT_CLOSE);
	tmp = get_left_cell(map, row, col);
	if (!tmp || *tmp == ' ')
		exit_cub3d(game, MAP_NOT_CLOSE);
}
