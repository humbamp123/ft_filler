/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:18:09 by apineda           #+#    #+#             */
/*   Updated: 2017/05/24 15:20:57 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void			ft_real_piece(t_piece *p)
{
	char	*tmp;

	p->row = p->save_row;
	p->height = p->real_height;
	while (p->row < p->height)
	{
		tmp = p->piece[p->row];
		if (ft_strchr(p->piece[p->row], '*') &&
			ft_strchr(p->piece[p->row], '*') - tmp < p->save_col)
			p->save_col = ft_strchr(p->piece[p->row], '*') - tmp;
		p->col = p->save_col;
		while (p->col < p->width)
		{
			p->real_width = p->piece[p->row][p->col] == '*' &&
				p->col >= p->real_width ? p->col + 1 : p->real_width;
			p->col++;
		}
		p->row++;
	}
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
	ft_arraydel(array, 3);
	ft_strdel(&str);
}

static	int				ft_piece_rows(t_piece *p, char *str, char *tmp)
{
	if (ft_strchr(str, '*') != NULL && !p->flag)
	{
		p->save_col = ft_strchr(str, '*') - tmp;
		p->save_row = p->row;
		p->flag = 1;
	}
	else if (ft_strchr(str, '*') == NULL && p->flag)
	{
		p->real_height = p->row;
		return (1);
	}
	return (0);
}

void					ft_save_piece(t_piece *p, char **str)
{
	char	**tmp;
	char	**piece_cpy;

	ft_piece_size(p);
	*str = NULL;
	piece_cpy = (char **)ft_memalloc(sizeof(char *) * p->height);
	while (p->row < p->height)
	{
		get_next_line(0, str);
		tmp = str;
		piece_cpy[p->row] = ft_strdup(*str);
		if (ft_piece_rows(p, *str, *tmp))
		{
			p->real_height = p->row;
			ft_strdel(tmp);
		}
		p->row++;
		ft_strdel(tmp);
	}
	p->real_height = !p->real_height ? p->row : p->real_height;
	p->real_width = !p->real_width ? p->col : p->real_width;
	p->piece = piece_cpy;
	ft_real_piece(p);
}
