/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:38:28 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 15:43:52 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void			ft_piece_size(t_piece *p)
{
	char	*str;
	char	**array;

	str = NULL;
	get_next_line(0, &str);
	array = ft_strsplit(str, ' ');
	p->h = ft_atoi(array[1]);
	p->w = ft_atoi(array[2]);
	ft_arraydel(array);
}

void					ft_save_piece(t_piece *p)
{
	ft_piece_size(p);
	p->i = 0;
	while (p->i < p->h)
	{
		while (p->j < p->w)
		{
			
		}
	}
}		