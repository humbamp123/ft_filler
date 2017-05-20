/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static	int	ft_u_negitoa(t_print *ret)
{
	ret->tmp = NULL;
	ERR((ret->tmp = ret->flags.ln_mod == 1 ?
		ft_itoa_base(ret->var, 10) : NULL) != NULL, 0);
	ERR((ret->tmp = ret->flags.ln_mod == 2 ?
		ft_itoa_base(ret->var, 10) : NULL) != NULL, 0);
	ERR((ret->tmp = ret->flags.ln_mod == 3 ?
		ft_itoa_base(ret->var, 10) : NULL) != NULL, 0);
	ERR((ret->tmp = ret->flags.ln_mod == 4 ?
		ft_itoa_base(ret->var, 10) : NULL) != NULL, 0);
	ERR((ret->tmp = ret->flags.ln_mod == 5 ?
		ft_itoa_base(ret->var + USHRT_MAX + 1, 10) : NULL)
		!= NULL, 0);
	ERR((ret->tmp = ret->flags.ln_mod == 6 ?
		ft_itoa_base(ret->var + UCHAR_MAX + 1, 10) : NULL)
		!= NULL, 0);
	return (0);
}

static int	ft_u_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = (!ret->flags.in_pres && ret->neg) || ret->flags.plus ||
		ret->flags.space ? ret->flags.width - (int)ft_strlen(ret->tmp) :
		ret->flags.width - (int)ft_strlen(ret->tmp);
	ERR(spacelen <= 0, 0);
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

static int	ft_u_precision(t_print *ret)
{
	char	*temp;
	int		zerolen;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) <= ret->flags.pres)
	{
		zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp);
		ERR(zerolen <= 0, 0);
		temp = ft_strnew(zerolen + 1);
		ft_memset(temp, '0', zerolen);
		ret->tmp = ft_appender(temp, ret->tmp);
		ret->flags.pres = ft_strlen(ret->tmp);
	}
	return (0);
}

int			ft_printf_u(t_print *ret, const char **fmt, va_list arg)
{
	ret->flags.ln_mod = **fmt == 'U' ? 3 : ret->flags.ln_mod;
	ft_new_len(ret, arg);
	ERR1(ret->flags.in_pres && (long long)ret->var == 0 && ret->flags.pres
		== 0, (*fmt)++, 1);
	ret->neg = (long long)ret->var < 0 ? 1 : 0;
	if (ret->flags.ln_mod && ret->neg)
		ft_u_negitoa(ret);
	else
		ret->tmp = ret->neg ? ft_itoa_base((unsigned)ret->var, 10) :
			ft_itoa_base(ret->var, 10);
	if (ret->flags.in_pres == 1)
		ft_u_precision(ret);
	if (ret->flags.width && ret->flags.width > ret->flags.pres)
		ft_u_width(ret);
	ret->fin = ft_appender(ret->fin, ret->tmp);
	(*fmt)++;
	return (1);
}
