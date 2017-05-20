/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_per_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = ret->tmp[0] != 0 ? ret->flags.width - (int)ft_strlen(ret->tmp) :
		ret->flags.width - 1;
	temp = ft_strnew(spacelen + 1);
	if ((!ret->flags.in_pres || ret->flags.pres < (int)ft_strlen(ret->tmp)) &&
		!ret->flags.minus && ret->flags.zero)
	{
		ft_memset(temp, '0', spacelen);
		ret->tmp = ft_appender(temp, ret->tmp);
	}
	else
	{
		ft_memset(temp, ' ', spacelen);
		ret->tmp = ret->flags.minus ? ft_appender(ret->tmp, temp) :
			ft_appender(temp, ret->tmp);
	}
	return (0);
}

static int	ft_per_precision(t_print *ret)
{
	char	*temp;

	if ((int)ft_strlen(ret->tmp) > ret->flags.pres && ret->flags.pres > 0)
	{
		temp = ft_strsub(ret->tmp, 0, ret->flags.pres);
		ft_strdel(&ret->tmp);
		ret->tmp = temp;
	}
	return (0);
}

int			ft_printf_per(t_print *ret, const char **fmt, va_list arg)
{
	ret->tmp = ft_strnew(2);
	ret->tmp[0] = **fmt;
	if (ret->flags.in_pres == 1 && ret->flags.pres)
	{
		ERR2(ret->flags.pres == 0, ft_strdel(&ret->tmp), (*fmt)++, 1);
		ft_per_precision(ret);
	}
	if (ret->flags.width && ret->flags.width > (int)ft_strlen(ret->tmp))
		ft_per_width(ret);
	ERR((ret->fin = ft_appender(ret->fin, ret->tmp)) == 0, -1);
	(*fmt)++;
	return (1);
	(void)arg;
}
