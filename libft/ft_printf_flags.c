/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 18:02:17 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_signed(t_print *ret)
{
	if (ret->flags.ln_mod == 1)
		ret->tmp = (intmax_t)ret->var < 0 ? ft_itoa_base(-(intmax_t)ret->var,
			10) : ft_itoa_base((intmax_t)ret->var, 10);
	else if (ret->flags.ln_mod == 2)
		ret->tmp = (intmax_t)ret->var < 0 ? ft_itoa_base(-(size_t)ret->var,
			10) : ft_itoa_base((size_t)ret->var, 10);
	else if (ret->flags.ln_mod == 3)
		ret->tmp = (long)ret->var < 0 ? ft_itoa_base(-(long)ret->var,
			10) : ft_itoa_base((long)ret->var, 10);
	else if (ret->flags.ln_mod == 4)
		ret->tmp = (long long)ret->var < 0 ? ft_itoa_base(-(long long)ret->var,
			10) : ft_itoa_base((long long)ret->var, 10);
	else if (ret->flags.ln_mod == 5)
		ret->tmp = (short)ret->var < 0 ? ft_itoa_base(-(short)ret->var,
			10) : ft_itoa_base((short)ret->var, 10);
	else if (ret->flags.ln_mod == 6)
		ret->tmp = (char)ret->var < 0 ? ft_itoa_base(-(char)ret->var,
			10) : ft_itoa_base((char)ret->var, 10);
	return (0);
}

int		ft_printf_flg(t_print *ret, const char **fmt, va_list arg)
{
	while (**fmt && (**fmt == ' ' || **fmt == '-' || **fmt == '+' ||
		**fmt == '#' || **fmt == '0'))
	{
		ret->flags.minus = **fmt == '-' ? 1 : ret->flags.minus;
		ret->flags.space = **fmt == ' ' ? 1 : ret->flags.space;
		ret->flags.plus = **fmt == '+' ? 1 : ret->flags.plus;
		ret->flags.pound = **fmt == '#' ? 1 : ret->flags.pound;
		ret->flags.zero = **fmt == '0' ? 1 : ret->flags.zero;
		ret->flags.flgs = 1;
		++(*fmt);
	}
	return (0);
	(void)arg;
}

char	*ft_wide_char(wchar_t var)
{
	char	*temp;

	temp = ft_strnew(4);
	if (var <= 127)
		temp[0] = var;
	else if (var <= 2047)
	{
		temp[0] = 192 | (var >> 6);
		temp[1] = 128 | (var & 63);
	}
	else if (var <= 65535)
	{
		temp[0] = 224 | (var >> 12);
		temp[1] = 128 | (var >> 6 & 63);
		temp[2] = 128 | (var & 63);
	}
	else if (var <= 131071)
	{
		temp[0] = 240 | (var >> 18);
		temp[1] = 128 | (var >> 12 & 63);
		temp[2] = 128 | (var >> 6 & 63);
		temp[3] = 128 | (var & 63);
	}
	return (temp);
}

int		ft_queenies_crazy_write(int fd, char *str, int len)
{
	char null;

	null = '\0';
	if (!(ft_strchr(str, 7)))
		write(fd, str, len);
	else
		while (len--)
		{
			if (*str == 7)
				write(fd, &null, 1);
			else
				ERR(write(fd, &*str, 1) == -1, -1);
			str++;
		}
	return (1);
}
