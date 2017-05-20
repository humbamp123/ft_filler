/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:34:20 by apineda           #+#    #+#             */
/*   Updated: 2016/10/17 13:20:07 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			if (f(s[i]))
			{
				save[j] = f(s[i]);
				j++;
			}
			i++;
		}
	}
	return (save);
}
