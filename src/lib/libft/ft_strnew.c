/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:33:51 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 01:14:58 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (!(str = malloc(size + 1)))
		return (NULL);
	if (size)
		ft_bzero(str, size + 1);
	return (str);
}
