/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:55:23 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 18:03:58 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*tmp;

	head = (t_list*)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		list = (t_list*)malloc(sizeof(t_list));
		if (list == NULL)
			return (NULL);
		list = (f)(lst);
		if (tmp != NULL)
			tmp->next = list;
		else
			head = list;
		tmp = list;
		lst = lst->next;
	}
	return (head);
}
