/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:11:58 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/01 11:12:03 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 - *(unsigned char *)s2 != 0)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
		{
			n--;
			s1++;
			s2++;
		}
	}
	return (0);
}
