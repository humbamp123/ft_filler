/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:30:49 by apineda           #+#    #+#             */
/*   Updated: 2016/10/01 16:19:51 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*destin;
	char			*source;

	destin = dest;
	source = (char *)src;
	while (n--)
	{
		*destin = *source;
		if (*source == c)
		{
			destin++;
			return (destin);
		}
		destin++;
		source++;
	}
	return (0);
}
