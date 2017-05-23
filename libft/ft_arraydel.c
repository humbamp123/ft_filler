/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:21:43 by apineda           #+#    #+#             */
/*   Updated: 2017/05/22 14:47:25 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **arr, int size)
{
	int	i;

	if (arr && *arr)
	{
		i = 0;
		while (i < size)
			free(arr[i++]);
		free(arr);
	}
}
