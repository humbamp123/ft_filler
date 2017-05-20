/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 00:35:07 by apineda           #+#    #+#             */
/*   Updated: 2017/02/21 20:37:27 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = NULL;
	if ((cpy = ft_strnew(ft_strlen(s1))))
		cpy = ft_strcpy(cpy, s1);
	return (cpy);
}
