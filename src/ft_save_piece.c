/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:38:28 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 01:00:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void			ft_real_piece(t_piece *p)
{
	char	*tmp;

	p->row = p->savey;
	p->real_height = p->height;
	p->height = p->savex;
	ft_dprintf(1, "before = %d\n", p->savex);
	while (p->row < p->height)
	{
		tmp = p->piece[p->row];
		ft_dprintf(2, "strchr = %d\n", ft_strchr(p->piece[p->row], '*') - tmp);
		if (ft_strchr(p->piece[p->row], '*') &&
			ft_strchr(p->piece[p->row], '*') - tmp < p->savex)
			p->savex = ft_strchr(p->piece[p->row], '*') - tmp;
		if (!ft_strchr(p->piece[p->row], '*') && p->row < p->real_height && p->row > p->savey)
			p->real_height = p->row
		p->col = p->savex;
		while (p->col < p->width)
			p->real_width = p->piece[p->row][p->col] == '*' && p->col > p->real_width ? p->col++ : p->real_width;
		ft_dprintf(2, "row = %d height = %d", p->row, p->height);
		p->row++;
	}
	ft_dprintf(1, "after = %d\n", p->savex);
}

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
	char	*tmp;
	char	**array;
	char	**piece_cpy;

	ft_piece_size(p);
	str = NULL;
	piece_cpy = (char **)ft_memalloc(sizeof(char *) * p->height);
	while (p->row < p->height)
	{
		get_next_line(0, &str);
		tmp = str;
		piece_cpy[p->row] = ft_strdup(str);
		if (ft_strchr(str, '*') != NULL && !p->flag)
		{
			p->savex = ft_strchr(str, '*') - tmp;
			p->savey = p->row;
			p->flag = 1;
		}
		p->row++;
		ft_strdel(&tmp);
	}
	p->piece = piece_cpy;
	ft_real_piece(p);
}
