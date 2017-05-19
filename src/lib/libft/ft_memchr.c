/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:06:32 by apineda           #+#    #+#             */
/*   Updated: 2016/10/08 14:38:43 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*source;

	source = (unsigned char *)s;
	while (len--)
	{
		if (*source == (unsigned char)c)
			return (source);
		source++;
	}
	return (NULL);
}
