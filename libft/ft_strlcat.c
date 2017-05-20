/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:14:13 by apineda           #+#    #+#             */
/*   Updated: 2016/10/17 14:24:14 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*source;
	size_t		num;
	size_t		length;

	dest = dst;
	source = src;
	num = size;
	while (num-- != 0 && *dest != '\0')
		dest++;
	length = dest - dst;
	num = size - length;
	if (num == 0)
		return (length + ft_strlen(source));
	while (*source != '\0')
	{
		if (num != 1)
		{
			*dest++ = *source;
			num--;
		}
		source++;
	}
	*dest = '\0';
	return (length + (source - src));
}
