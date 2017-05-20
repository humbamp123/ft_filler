/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cap_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:41:26 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 21:06:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_cap_s_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = ret->tmp != 0 ? ret->flags.width - (int)ft_strlen(ret->tmp) :
		ret->flags.width;
	temp = ft_strnew(spacelen + 1);
	if ((!ret->flags.in_pres || ret->flags.pres <= (int)ft_strlen(ret->tmp)) &&
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

static int	ft_cap_s_precision(t_print *ret)
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

static	int	ft_cap_s_wide_char(wchar_t *temp, t_print *ret)
{
	char	*temper;

	ret->tmp = ft_strdup("\0");
	while (*temp)
	{
		temper = ft_wide_char(*temp++);
		ERR1(ret->flags.in_pres && (int)ft_strlen(temper) +
			(int)ft_strlen(ret->tmp) > ret->flags.pres, ft_strdel(&temper), 0);
		ERR((ret->tmp = ft_appender(ret->tmp, temper)) == 0, -1);
	}
	return (0);
}

int			ft_printf_c_s(t_print *ret, const char **fmt, va_list arg)
{
	wchar_t	*temp;

	temp = va_arg(arg, wchar_t*);
	if (temp != 0)
	{
		if (ret->flags.width && ret->flags.in_pres && !ret->flags.pres)
			ret->tmp = ft_strdup("\0");
		else
			ft_cap_s_wide_char(temp, ret);
		ERR2(ret->flags.in_pres && ret->flags.pres == 0 && !ret->flags.width,
			ft_strdel(&ret->tmp), (*fmt)++, 1);
		if (ret->flags.in_pres == 1 && ret->flags.pres != 0)
			ft_cap_s_precision(ret);
		if (ret->flags.width && ret->flags.width > (int)ft_strlen(ret->tmp))
			ft_cap_s_width(ret);
		ERR((ret->fin = ft_appender(ret->fin, ret->tmp)) == 0, -1);
	}
	else if (!ret->tmp && !ret->flags.pres && ret->flags.in_pres)
		ft_cap_s_width(ret);
	else
		ERR((ret->fin = ft_appender(ret->fin,
			ft_strdup("(null)\0"))) == 0, -1);
	(*fmt)++;
	return (1);
}
