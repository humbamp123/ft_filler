/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_white.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:39:37 by apineda           #+#    #+#             */
/*   Updated: 2016/10/17 13:17:49 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_back_white(char const *str)
{
	int		i;
	int		j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (j)
	{
		if (str[j] == ' ' || str[j] == '\n' || str[j] == '\t'
				|| str[j] == '\v' || str[j] == '\f' || str[j] == '\r')
			i++;
		else
			break ;
		j--;
	}
	return (i);
}
