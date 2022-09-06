/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:11:42 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/06 15:12:16 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdbool.h>

/*
** Return true only if s contain accepted chars
*/
bool	ft_isin(const char *s, const char *accepted)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(accepted, s[i]))
			i++;
		else
			return (false);
	}
	return (true);
}
