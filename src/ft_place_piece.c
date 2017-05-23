/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:28:54 by andres            #+#    #+#             */
/*   Updated: 2017/05/23 00:05:06 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	ft_zone_count(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = m->row + p->save_row - p->real_height;
	p->check_row = p->save_row;
	p->z_cnter = 0;
	while (i < m->height && p->check_row < p->real_height)
	{
		j = m->col + p->save_row - p->real_width;
		p->check_col = 0;
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

	ft_dprintf(2, "mrow = %d, mcol = %d, psrow = %d, pscol = %d, pheight = %d, pwidth = %d, subrow = %d, subcol = %d\n",
		m->row, m->col, p->save_row, p->save_col, p->height, p->width, m->row - p->height * (p->row + p->save_row), m->col - p->real_width * (p->col + p->save_col));
	ERR(m->row + p->row - p->real_height < 0 || m->col + p->save_col - p->real_width < 0, 0);
	i = m->row - p->real_height * (p->row + p->save_row);
	p->check_row = p->save_row;
	while (i < m->height && p->check_row < p->real_height)
	{
		j = m->col - p->real_width * (p->col + p->save_col);
		p->check_col = p->save_col;
		while (j < m->width && p->check_col < p->real_width)
		{
			if (m->map[i][j] == m->player &&
					p->piece[p->check_row][p->check_col] == '*')
				p->count++;
			ERR((p->piece[p->check_row][p->check_col] == '*' &&
				m->map[i][j] == m->enemy) || p->count > 1, 0);
			j++;
			p->check_col++;
		}
		p->check_row++;
		i++;
	}
	ft_dprintf(2, "prow = %d, pcol = %d, pheight = %d, pwidth = %d\n", p->check_row, p->check_col, p->real_height, p->real_width);
	ERR(p->check_row < p->real_height || p->check_col < p->real_width, 0);
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
	ft_dprintf(2, "\nHERE row = %d, p->height = %d\n", p->row , p->real_height);
	while (p->row < p->real_height)
	{
		p->col = p->save_col;
		while (p->col < p->real_width)
		{
			ft_dprintf(2, "\nHERE col = %d, p->width = %d\n", p->col , p->real_width);
			p->count = 0;
			if (p->piece[p->row][p->col] == '*' && (!ft_piece_reject(p) ||
					!ft_piece_check(m, p)))
			{
				ft_dprintf(2, "REJECTED? ft_piece_check = %d, or ft_piece_reject = %d\n", !ft_piece_reject(p), !ft_piece_check(m, p));
			}
			else if (p->piece[p->row][p->col] == '*')
			{
				ft_zone_count(m, p);
				if ((p->z_cnter = !p->z_cnter ? 1 : p->z_cnter) >= p->z_count)
				{
					ft_dprintf(2, "\nHERE\n");
					p->z_count = p->z_cnter;
					p->ret_col = m->col - p->col;
					p->ret_row = m->row - p->row;
					ft_dprintf(1, "retcol = %d, retrow = %d", p->ret_col, p->ret_row);
				}
			}
			p->col++;
		}
		p->row++;
	}
}

void			ft_place_piece(t_map *m, t_piece *p)
{
	m->row = 0;
	p->ret_row = 0;
	p->ret_col = 0;
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
	// ft_dprintf(2, "%d %d\n", p->ret_row, p->ret_col);
	ft_printf("%d %d\n", p->ret_row, p->ret_col);
	ft_arraydel(p->piece, p->real_height);
	ft_arraydel(m->map, m->height);
}
