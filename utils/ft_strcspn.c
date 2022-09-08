/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:38:08 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/08 19:36:54 by naben-za         ###   ########.fr       */
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
	while (*s && !ft_strchr(rejected, *s))
	{
		++s;
		++len;
	}
	return (len);
}