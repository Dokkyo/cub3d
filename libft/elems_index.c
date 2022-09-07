/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:13 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 14:45:14 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	elems_index(char *s1, char *s2)
{
	int	i;
	int	index;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i])
		{
			index = elem_index(s2, s1[i]);
			if (index > -1)
				return (elem_index(s1, s2[index]));
			i++;
		}
	}
	return (-1);
}
