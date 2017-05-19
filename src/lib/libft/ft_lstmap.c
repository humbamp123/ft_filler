/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 22:47:57 by apineda           #+#    #+#             */
/*   Updated: 2016/10/20 23:16:03 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	list = NULL;
	if (lst)
	{
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (list);
}
