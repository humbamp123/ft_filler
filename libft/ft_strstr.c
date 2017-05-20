/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:30:38 by apineda           #+#    #+#             */
/*   Updated: 2016/10/23 18:43:34 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		iter[2];

	ft_bzero((void*)iter, sizeof(int) * 2);
	if ((little[iter[0]]) == '\0')
		return ((char *)big);
	while (big[iter[0]] != '\0')
		if (big[iter[0]] == little[iter[1]])
		{
			if (little[iter[1] + 1] == '\0')
				return ((char *)&big[iter[0] - iter[1]]);
			iter[0]++;
			iter[1]++;
		}
		else
		{
			if (iter[1] > 0)
				iter[0] = iter[0] - iter[1];
			iter[0]++;
			iter[1] = 0;
		}
	return (0);
}
