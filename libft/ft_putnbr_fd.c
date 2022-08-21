/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:01:00 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 13:03:04 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar(fd, '-');
		n = -n;
	}
	if (n == -2147483648)
	{
		write(fd, "2", 1);
		n = 147483648;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar(fd, '0' + n % 10);
}
