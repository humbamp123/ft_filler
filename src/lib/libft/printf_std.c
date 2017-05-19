/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_std.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:42:08 by apineda           #+#    #+#             */
/*   Updated: 2017/05/12 00:09:02 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char		*ft_appendit(t_print *ret, char *str)
{
	char		*temp;

	if (str && ret->save)
	{
		temp = ft_strjoin(ret->fin, str);
		ft_strdel(&ret->fin);
		ret->fin = temp;
	}
	else if (str && !(ret->save))
	{
		ret->fin = ft_strdup(str);
		ft_strdel(&str);
	}
	return (ret->fin);
}

char		*ft_appender(char *ret, char *str)
{
	char	*temp;

	if (str && ret)
	{
		temp = ft_strjoin(ret, str);
		ft_strdel(&ret);
		ft_strdel(&str);
		ret = temp;
	}
	else if (str && !(ret))
	{
		ret = ft_strdup(str);
		ft_strdel(&str);
	}
	return (ret);
}

static int	ft_upper(int c)
{
	return (c >= 'a' && c <= 'z' ? c - 32 : c);
}

char		*ft_to_upper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_upper(str[i]);
		i++;
	}
	return (str);
}
