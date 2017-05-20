/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:27:16 by apineda           #+#    #+#             */
/*   Updated: 2016/09/30 11:59:08 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		j;
	char	*dest;
	char	*source;

	j = len;
	dest = (char *)dst;
	source = (char *)src;
	if (source == dest)
		return (dst);
	else if (source > dest)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		dest = dest + j - 1;
		source = source + j - 1;
		while (j--)
			*dest-- = *source--;
	}
	return (dst);
}
