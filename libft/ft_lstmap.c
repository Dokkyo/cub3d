/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:58:28 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 14:41:00 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*elem;

	head = NULL;
	if (lst && f)
	{		
		while (lst)
		{
			elem = ft_lstnew(f(lst->content));
			if (!elem)
			{
				ft_lstclear(&head, del);
				return (head);
			}				
			ft_lstadd_back(&head, elem);
			lst = lst->next;
		}
	}
	return (head);
}
