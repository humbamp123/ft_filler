/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:38:28 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 20:50:01 by andres           ###   ########.fr       */
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
	p->height = ft_atoi(array[1]);
	p->width = ft_atoi(array[2]);
	ft_arraydel(array);
	ft_strdel(&str);
}

void					ft_save_piece(t_piece *p)
{
	char	*str;
	char	**array;
	char	**piece_cpy;

	ft_piece_size(p);
	str = NULL;
	p->row = 0;
	piece_cpy = (char **)ft_memalloc(sizeof(char *) * p->height);
	while (p->row < p->height)
	{
		get_next_line(0, &str);
		piece_cpy[p->row++] = ft_strdup(str);
		ft_strdel(&str);
	}
	p->piece = piece_cpy;
	p->row = 0;
	while (p->row < p->height)
	{
		ft_dprintf(2, "%d: %s\n", p->row, p->piece[p->row]);
		p->row++;
	}
}
