/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:58:36 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:58:40 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(uintmax_t num, short base)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = 0;
	while (num != 0)
	{
		num = num / base;
		++flag;
	}
	return (flag);
}

char		*ft_itoa_base(uintmax_t nbr, short base)
{
	char	*str;
	int		len;
	int		end;

	len = ft_nbrlen_base(nbr, base);
	end = len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (--len)
	{
		str[len] = HEX[nbr % base];
		nbr = nbr / base;
	}
	str[len] = HEX[nbr % base];
	str[end] = '\0';
	return (str);
}
