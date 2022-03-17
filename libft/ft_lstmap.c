/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:42:03 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 16:37:24 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	new = NULL;
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		list = ft_lstnew((*f)(lst->content));
		if (!list)
			ft_lstclear(&new, (*del));
		ft_lstadd_back(&new, list);
		lst = lst -> next;
	}
	return (new);
}
