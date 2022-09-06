/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:11:23 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/06 15:11:24 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*
** Return an index of the first character of 's' which is not in 'rejected'
*/
int	ft_strcspn(const char *s, const char *rejected)
{
	int	len;

	len = 0;
	while (*s && ft_strchr(rejected, *s))
		++s;
	while (*s && !ft_strchr(rejected, *s) && *s != '\n')
	{
		++s;
		++len;
	}
	return (len);
}

int	ft_strcspn2(const char *s, const char *rejected)
{
	int	len;

	len = 0;
	while (*s && ft_strchr(rejected, *s))
		++s;
	while (*s && !ft_strchr(rejected, *s))
	{
		++s;
		++len;
	}
	return (len);
}
