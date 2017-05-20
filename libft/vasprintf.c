/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vasprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:08:05 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 17:57:13 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define COUNT 38
#define SIZE 3

static	char	g_ary[COUNT][SIZE] = {
	{"-"}, {"+"}, {" "}, {"#"},
	{"0"}, {"*"}, {"1"}, {"2"},
	{"3"}, {"4"}, {"5"}, {"6"},
	{"7"}, {"8"}, {"9"}, {"*"},
	{"."}, {"j"}, {"z"}, {"ll"},
	{"l"}, {"hh"}, {"h"}, {"s"},
	{"d"}, {"i"}, {"u"}, {"o"},
	{"x"}, {"X"}, {"D"}, {"O"},
	{"U"}, {"c"}, {"C"}, {"S"},
	{"p"}, {"%"}};

static	int		(*g_ft_ptr[COUNT]) (t_print *ret, const char **fmt,
	va_list arg) = {
	ft_printf_flg, ft_printf_flg, ft_printf_flg, ft_printf_flg,
	ft_printf_flg, ft_width, ft_width, ft_width,
	ft_width, ft_width, ft_width, ft_width,
	ft_width, ft_width, ft_width, ft_width,
	ft_precision, ft_len_mod, ft_len_mod, ft_len_mod,
	ft_len_mod, ft_len_mod, ft_len_mod, ft_printf_s,
	ft_printf_d, ft_printf_d, ft_printf_u, ft_printf_o,
	ft_printf_x, ft_printf_x, ft_printf_d, ft_printf_o,
	ft_printf_u, ft_printf_c, ft_printf_c, ft_printf_c_s,
	ft_printf_p, ft_printf_per};

static size_t	flag_checker(t_print *ret, const char **fmt, va_list arg)
{
	int			i;
	int			rtn;

	i = 0;
	ft_bzero(&ret->flags, sizeof(ret->flags));
	while (i < COUNT)
	{
		if (**fmt && (ft_strnstr(*fmt, g_ary[i], ft_strlen(g_ary[i]))) != NULL)
		{
			ERR((rtn = (*g_ft_ptr[i])(ret, fmt, arg)) == -1, -1);
			if (i < 23)
				i = 0;
			if (rtn > 0)
				return (1);
		}
		i++;
	}
	ERR(**fmt == 0, 0);
	ERR((rtn = ft_printf_per(ret, fmt, arg)) == -1, -1);
	if (rtn > 0)
		return (1);
	return (0);
}

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	t_print		list;
	int			i;

	ft_bzero(&list, sizeof(list));
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '\0' && fmt[i] != '%')
			i++;
		ERR((list.text = ft_strsub(fmt, 0, i)) == NULL, -1);
		ERR((list.fin = ft_appendit(&list, list.text)) == NULL, -1);
		if (list.save != 0)
			ft_strdel(&list.text);
		else if (list.fin)
			list.save = 1;
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0)
				break ;
			ERW((i = flag_checker(&list, &fmt, arg)) == -1, -1, "Flag Error");
		}
	}
	*ret = list.fin;
	return (ft_strlen(list.fin));
}

int				ft_vasprintf(char **ret, const char *fmt, va_list arg)
{
	int		r;

	if (!*fmt || !fmt || !ret)
		return (0);
	*ret = NULL;
	if (!(ft_strchr(fmt, '%')))
	{
		ERW((*ret = ft_strdup(fmt)) == 0, -1, "Strdup Error");
		return (ft_strlen(fmt));
	}
	r = checkthrough(ret, fmt, arg);
	return (r);
}
