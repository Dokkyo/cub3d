/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:37:29 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 16:37:29 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_to_image(t_image *image, int x, int y, int color)
{
	image->addr[y * WIN_SIZE + x] = color;
}

int	get_image_pixel_color(t_image *image, int col, int row)
{
	return ((int)image->addr[row * CUB_SIZE + col]);
}
