/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:00:16 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 14:18:32 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*dst;

	if (n == 0)
		return (s);
	dst = s;
	while (n > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		n--;
	}
	return (s);
}
