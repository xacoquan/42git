/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:06:54 by smarie-c          #+#    #+#             */
/*   Updated: 2015/02/18 16:07:00 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*tmp;
	t_list		*map;

	if (!lst)
		return (NULL);
	map = (*f)(lst);
	head = ft_lstnew(map->content, map->content_size);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		map = (*f)(lst);
		tmp->next = ft_lstnew(map->content, map->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
