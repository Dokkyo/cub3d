/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:59:55 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 12:59:58 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char		*ptr_s;
	unsigned int		i;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i++ < n)
	{
		if (*ptr_s == (unsigned char)c)
		{
			return (ptr_s);
		}
		else
			ptr_s++;
	}
	return (NULL);
}
