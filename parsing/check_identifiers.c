/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:39:04 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 15:54:23 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_color_digits(char *tmp)
{
	if (ft_isin(tmp, BASE_DEC_SPACE))
		return (true);
	else
		return (false);
}

bool	check_color_range(char *tmp)
{
	int	color;

	color = ft_atoi(tmp);
	if (color < 0 || color > 255)
		return (false);
	return (true);
}
