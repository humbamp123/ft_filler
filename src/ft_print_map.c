/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:34:24 by apineda           #+#    #+#             */
/*   Updated: 2017/05/22 18:57:18 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void			ft_print_map(t_map m)
{
	ft_dprintf(2, "\n\0\0\0\0\0\0\0\0\n");
	m.row = 0;
	while (m.row < m.height)
	{
		m.col = 0;
		while (m.col < m.width)
		{
			if (m.map[m.row][m.col] == m.player)
				ft_dprintf(2, "%s%c%s", C, m.map[m.row][m.col], W);
			else if (m.map[m.row][m.col] == m.enemy)
				ft_dprintf(2, "%s%c%s", B, m.map[m.row][m.col], W);
			else if (m.map[m.row][m.col] >= '3')
				ft_dprintf(2, "%s%c%s", R, m.map[m.row][m.col], W);
			else if (m.map[m.row][m.col] == '2')
				ft_dprintf(2, "%s%c%s", Y, m.map[m.row][m.col], W);
			else if (m.map[m.row][m.col] == '1')
				ft_dprintf(2, "%s%c%s", G, m.map[m.row][m.col], W);
			else
				ft_dprintf(2, "%s%c%s", G, m.map[m.row][m.col], W);
			m.col++;
		}
		ft_dprintf(2, "\n");
		m.row++;
	}
	ft_dprintf(2, "\n");
}

int				ft_map_reject(t_map *m)
{
	ERR(!m->row || !m->col ||
		m->row == m->height - 1 || m->col == m->width - 1, 1);
	ERR(m->map[m->row - 1][m->col - 1] == m->player &&
		m->map[m->row - 1][m->col] == m->player &&
		m->map[m->row - 1][m->col + 1] == m->player &&
		m->map[m->row][m->col - 1] == m->player &&
		m->map[m->row][m->col + 1] == m->player &&
		m->map[m->row + 1][m->col - 1] == m->player &&
		m->map[m->row + 1][m->col] == m->player &&
		m->map[m->row + 1][m->col + 1] == m->player, 0);
	return (1);
}

void			ft_rev_place_piece(t_map *m, t_piece *p)
{
	m->row = m->height - 1;
	p->ret_row = 0;
	p->ret_col = 0;
	while (0 <= m->row)
	{
		m->col = m->width - 1;
		while (0 <= m->col)
		{
			if (m->map[m->row][m->col] == m->player && ft_map_reject(m))
				ft_try_piece_here(m, p);
			m->col--;
		}
		m->row--;
	}
	ft_printf("%d %d\n", p->ret_row, p->ret_col);
	ft_arraydel(p->piece, p->real_height);
	ft_arraydel(m->map, m->height);
}
