/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 00:25:16 by apineda           #+#    #+#             */
/*   Updated: 2016/10/08 00:25:20 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s2[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != s2[i] && i < n)
		{
			a = s2[i];
			b = s1[i];
			return (b - a);
		}
		else
			i++;
	}
	return (0);
}
