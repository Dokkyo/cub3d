/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:59:01 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 12:59:05 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	intl(int n)
{
	unsigned int	i;
	long int		nb;

	nb = n;
	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	len;
	long int		nb;

	nb = n;
	len = intl(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (nbr);
	nbr[len--] = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		nbr[0] = nb % 10 + '0';
	while (nb > 0)
	{
		nbr[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (nbr);
}
