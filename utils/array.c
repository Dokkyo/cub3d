/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:36:37 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/08 19:37:17 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	length_2d_array(char **a)
{
	int	i;

	i = -1;
	if (a)
	{
		i = 0;
		while (a[i])
			i++;
	}
	return (i);
}

void	free_2d_array(char **a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
}

void	skip_digits(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}

void	skip_spaces(char **s)
{
	while (**s == ' ')
		(*s)++;
}
