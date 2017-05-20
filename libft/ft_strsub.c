/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 09:18:57 by apineda           #+#    #+#             */
/*   Updated: 2017/04/03 15:58:17 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len)
	{
		str = ft_strnew(len + 1);
		*str = '\0';
		return (str);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (!s)
		return (NULL);
	if (str)
		ft_strncpy(str, &s[start], len);
	return (str);
}
