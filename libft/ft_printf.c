/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:41:26 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 21:06:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		len;

	ERR(format == 0 || *format == 0, 0);
	va_start(args, format);
	ERR((len = ft_vasprintf(&str, format, args)) == -1, -1);
	ERR2(ft_queenies_crazy_write(1, str, len) == -1, va_end(args),
		ft_strdel(&str), -1);
	ft_strdel(&str);
	va_end(args);
	return (len);
}

int		ft_vprintf(const char *format, va_list args)
{
	char	*str;
	int		len;

	ERR(format == 0 || *format == 0, 0);
	ERR((len = ft_vasprintf(&str, format, args)) == -1, -1);
	ERR1(ft_queenies_crazy_write(1, str, len) == -1, ft_strdel(&str), -1);
	ft_strdel(&str);
	return (len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	char	*str;
	int		len;

	ERR(format == 0 || *format == 0 || fd < 0, 0);
	va_start(args, format);
	ERR((len = ft_vasprintf(&str, format, args)) == -1, -1);
	ERR2(ft_queenies_crazy_write(fd, str, len) == -1, va_end(args),
		ft_strdel(&str), -1);
	ft_strdel(&str);
	va_end(args);
	return (len);
}

int		ft_vdprintf(int fd, const char *format, va_list args)
{
	char	*str;
	int		len;

	ERR(format == 0 || *format == 0 || fd < 0, 0);
	ERR((len = ft_vasprintf(&str, format, args)) == -1, -1);
	ERR1(ft_queenies_crazy_write(fd, str, len) == -1, ft_strdel(&str), -1);
	ft_strdel(&str);
	return (len);
}

int		ft_asprintf(char **str, const char *format, ...)
{
	va_list	args;
	int		len;

	ERR(format == 0 || *format == 0 || str == 0, 0);
	va_start(args, format);
	ERR1((len = ft_vasprintf(str, format, args)) == -1, va_end(args), -1);
	va_end(args);
	return (len);
}
