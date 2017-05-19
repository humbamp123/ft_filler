/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:40 by apineda           #+#    #+#             */
/*   Updated: 2016/10/17 14:24:01 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = ft_strlen(src);
	while (i)
	{
		if (src[i] == c)
			return (&src[i]);
		i--;
	}
	if (src[0] == c)
		return (&src[0]);
	return (0);
}
