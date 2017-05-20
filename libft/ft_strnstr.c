/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:18:29 by apineda           #+#    #+#             */
/*   Updated: 2016/10/25 17:24:59 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *tiny, size_t len)
{
	int		iter[2];

	ft_bzero((void*)iter, sizeof(int) * 2);
	if (tiny[iter[0]] == '\0')
		return ((char *)big);
	while (big[iter[0]] != '\0' && len)
		if (big[iter[0]] == tiny[iter[1]])
		{
			if (tiny[iter[1] + 1] == '\0')
				return ((char *)&big[iter[0] - iter[1]]);
			iter[0]++;
			iter[1]++;
			len--;
		}
		else
		{
			if (iter[1] > 0)
				iter[0] = iter[0] - iter[1];
			if (iter[1] > 0)
				len = len + iter[1];
			iter[0]++;
			iter[1] = 0;
			len--;
		}
	return (0);
}
