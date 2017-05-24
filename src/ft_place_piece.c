/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:18:09 by apineda           #+#    #+#             */
/*   Updated: 2017/05/24 15:20:50 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	ft_zone_count(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = m->row + p->save_row - p->row;
	p->check_row = p->save_row;
	p->z_cnter = 0;
	while (i < m->height && p->check_row < p->real_height)
	{
		j = m->col + p->save_col - p->col;
		p->check_col = p->save_col;
		while (j < m->width && p->check_col < p->real_width)
		{
			if (ft_isdigit(m->map[i][j]) &&
					p->piece[p->check_row][p->check_col] == '*')
				p->z_cnter = p->z_cnter + m->map[i][j] - '0';
			p->check_col++;
			j++;
		}
		p->check_row++;
		i++;
	}
}

static	int		ft_piece_check(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	ERR(((i = m->row + p->save_row - p->row) < 0), 0);
	p->check_row = p->save_row;
	while (i < m->height && p->check_row < p->real_height)
	{
		ERR(((j = m->col + p->save_col - p->col) < 0), 0);
		p->check_col = p->save_col;
		while (j < m->width && p->check_col < p->real_width)
		{
			p->count = p->piece[p->check_row][p->check_col] == '*' &&
				m->map[i][j] == m->player ? p->count + 1 : p->count;
			ERR((p->piece[p->check_row][p->check_col] == '*' &&
				m->map[i][j] == m->enemy) || p->count > 1, 0);
			j++;
			p->check_col++;
		}
		p->check_row++;
		i++;
	}
	ERR(p->check_row < p->real_height || p->check_col < p->real_width ||
		p->count == 0, 0);
	return (1);
}

static	int		ft_piece_reject(t_piece *p)
{
	ERR(!p->row || !p->col ||
		p->row == p->real_height - 1 || p->col == p->real_width - 1, 1);
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

void			ft_try_piece_here(t_map *m, t_piece *p)
{
	p->row = p->save_row;
	while (p->row < p->real_height)
	{
		p->col = p->save_col;
		while (p->col < p->real_width)
		{
			p->count = 0;
			if (p->piece[p->row][p->col] == '*' && (!ft_piece_reject(p) ||
					!ft_piece_check(m, p)))
			{
			}
			else if (p->piece[p->row][p->col] == '*')
			{
				ft_zone_count(m, p);
				ft_save_ret(m, p);
			}
			p->col++;
		}
		p->row++;
	}
}

void			ft_place_piece(t_map *m, t_piece *p)
{
	m->row = 0;
	p->ret_row = -1;
	p->ret_col = -1;
	p->z_count = 0;
	while (m->row < m->height)
	{
		m->col = 0;
		while (m->col < m->width)
		{
			if (m->map[m->row][m->col] == m->player && ft_map_reject(m))
				ft_try_piece_here(m, p);
			m->col++;
		}
		m->row++;
	}
	ft_printf("%d %d\n", p->ret_row, p->ret_col);
	ft_arraydel(p->piece, p->real_height);
	ft_arraydel(m->map, m->height);
}
