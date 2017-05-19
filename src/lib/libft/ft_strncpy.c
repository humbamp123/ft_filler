/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fti_strncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 11:35:21 by apineda           #+#    #+#             */
/*   Updated: 2016/10/24 13:57:47 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	k = ft_strlen(src);
	while (i != n)
	{
		if (i >= k)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
