/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:28:54 by andres            #+#    #+#             */
/*   Updated: 2017/05/21 11:27:41 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	int		ft_zone_count(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = m->row;
	p->checky = -1;
	while (i < m->height && ++p->checky < p->real_height)
	{
		p->checkx = -1;
		j = m->col;
		while (j < m->width && ++p->checkx < p->real_width)
		{
			if(ft_isprint(m->map[i][j]) &&
					p->piece[p->checky][p->checkx] == '*')
				p->zone_count == m->map[i][j] - '0';
			j++;
		}
		i++;
	}
}

static	int		ft_piece_check(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	ERR(m->row - p->row < 0, 0);
	ERR(m->col - p->col < 0, 0);
	i = m->row - p->row;
	p->checky = -1;
	while (i < m->height && ++p->checky < p->real_height)
	{
		j = m->col - p->col;
		p->checkx = -1;
		while (j < m->width && ++p->checkx < p->real_width)
		{
			if(m->map[i][j] == m->player &&
					p->piece[p->checky][p->checkx] == '*')
				p->count++;
			ERR(m->map[i][j] != m->enemy &&
					p->piece[p->checky][p->checkx] == '*', 0);
			ERR(p->count > 1, 0);
			j++;
		}
		i++;
	}
	ERR(i < p->real_height || j < p->real_width, 0);
	return (1);
}

static	int		ft_piece_reject(t_map *m, t_piece *p)
{
	ERR(!p->row || !p->col ||
		p->row == p->real_height || p->col == p->real_width, 1);
	ERR(p->piece[p->row - 1][p->col - 1] == '*' && 
		p->piece[p->row - 1][p->col] == '*' &&
		p->piece[p->row - 1][p->col + 1] == '*' &&
		p->piece[p->row][p->col - 1] == '*' &&
		p->piece[p->row][p->col + 1] == '*' &&
		p->piece[p->row + 1][p->col - 1] == '*' &&
		p->piece[p->row + 1][p->col] == '*' &&
		p->piece[p->row + 1][p->col + 1] == '*', 0);
	return (1);
}

static	void	ft_try_piece_here(t_map *m, t_piece *p)
{
	p->row = p->savey;
	while (p->row < p->real_height)
	{
		p->col = p->savex;
		while (p->col < p->real_width)
		{
			if (p->piece[p->row][p->col] == '*' && !ft_piece_reject)
			{
			}
			else if (p->piece[p->row][p->col] == '*' && ft_piece_check(m, p)
						&& p->zone_count < ft_zone_count(m, p))
			{
				p->zone_count = ft_zone_count(m, p);
				p->ret_x = p->col - m->col;
				p->ret_y = p->row - m->row;
			}
			p->col++;
		}
		p->row++;
	}
}

void			ft_place_piece(t_map *m, t_piece *p)
{
	m->row = 0;
	p->zone_count = 0;
	while (m->row < m->height)
	{
		m->col = 0;
		while (m->col < m->width)
		{
			if(m->map[m->row][m->col] == m->player)
				ft_try_piece_here(m, p);
			m->col++;
		}
		m->row++;
	}
}