/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:25:08 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/01 09:33:30 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	unsigned int		i;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	while (i < n)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return (dest + i + 1);
		pdest++;
		psrc++;
		i++;
	}
	return (NULL);
}
