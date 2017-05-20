/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:44:08 by apineda           #+#    #+#             */
/*   Updated: 2016/10/01 16:29:28 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	int		len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (dst);
}
