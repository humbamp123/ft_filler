/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 22:06:00 by apineda           #+#    #+#             */
/*   Updated: 2016/10/29 16:20:40 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s2 || *s1)
	{
		if (*s1 != *s2)
		{
			a = *s2;
			b = *s1;
			return (b - a);
		}
		s1++;
		s2++;
	}
	return (0);
}
