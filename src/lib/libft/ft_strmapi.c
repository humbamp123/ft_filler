/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:17:35 by apineda           #+#    #+#             */
/*   Updated: 2016/10/17 13:05:41 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*save;

	save = NULL;
	i = 0;
	j = 0;
	if (s)
	{
		if (!(save = (char *)ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		while (i < (int)ft_strlen(s))
		{
			if (f(i, s[i]))
			{
				save[j] = f(i, s[i]);
				j++;
			}
			i++;
		}
	}
	return (save);
}
