/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:28:57 by apineda           #+#    #+#             */
/*   Updated: 2016/10/21 17:58:17 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		size;
	int		start;
	int		back;

	str = NULL;
	if (!s)
		return (NULL);
	start = ft_front_white(s);
	back = ft_back_white(s);
	if ((start == 0 && back == 0))
	{
		str = ft_strdup(s);
		return (str);
	}
	size = ft_absval(ft_strlen(&s[start]) - back);
	str = ft_strsub(s, start, size);
	return (str);
}
