/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:50:06 by apineda           #+#    #+#             */
/*   Updated: 2016/10/20 23:14:09 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst)
	{
		while (*alst)
		{
			list = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
			*alst = list;
		}
	}
}
