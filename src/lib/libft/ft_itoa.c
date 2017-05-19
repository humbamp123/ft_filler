/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:14:38 by exam              #+#    #+#             */
/*   Updated: 2017/05/11 13:35:02 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int			ft_nbrlen(intmax_t num)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = num < 0 ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		++flag;
	}
	return (flag);
}

char		*ft_itoa(intmax_t nbr)
{
	char	*str;
	int		len;
	int		flag;
	int		end;

	len = ft_nbrlen(nbr);
	end = len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	flag = nbr < 0 ? 1 : 0;
	nbr = flag ? -nbr : nbr;
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	str[len] = flag ? '-' : nbr % 10 + '0';
	str[end] = '\0';
	return (str);
}
