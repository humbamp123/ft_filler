/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static	int	ft_p_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = ret->tmp[0] != 0 ?
		ret->flags.width - (int)ft_strlen(ret->tmp) :
		ret->flags.width - 1;
	spacelen = ret->flags.width && ret->flags.zero ? spacelen - 2 : spacelen;
	temp = ft_strnew(spacelen + 1);
	if (!ret->flags.in_pres && !ret->flags.minus && ret->flags.zero)
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

static int	ft_p_precision(t_print *ret)
{
	char	*temp;
	int		zerolen;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) + 2 <= ret->flags.pres)
	{
		zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp) - 2;
		temp = ft_strnew(zerolen + 1);
		ft_memset(temp, '0', zerolen);
		ret->tmp = ft_appender(temp, ret->tmp);
		ret->flags.pres = ft_strlen(ret->tmp);
	}
	return (0);
}

int			ft_printf_p(t_print *ret, const char **fmt, va_list arg)
{
	char	*temp;

	temp = ft_strdup("0x\0");
	ret->var = (intmax_t)va_arg(arg, void *);
	ERR2(ret->flags.in_pres && (long long)ret->var == 0 && ret->flags.pres
		== 0, ret->fin = ft_appender(ret->fin, temp), (*fmt)++, 1);
	ret->tmp = ft_itoa_base((uintmax_t)ret->var, 16);
	if (ret->flags.in_pres == 1 && ret->flags.pres)
	{
		ret->flags.pres = ret->flags.pres + 2;
		ft_p_precision(ret);
	}
	ret->tmp = ret->flags.width > ret->flags.pres && !ret->flags.zero ?
		ft_appender(temp, ret->tmp) : ret->tmp;
	if (ret->flags.width && ret->flags.width > (int)ft_strlen(ret->tmp))
		ft_p_width(ret);
	ret->tmp = ft_strchr(ret->tmp, 'x') == NULL ? ft_appender(temp, ret->tmp) :
		ret->tmp;
	ERR((ret->fin = ft_appender(ret->fin, ret->tmp)) == 0, -1);
	(*fmt)++;
	return (1);
}
