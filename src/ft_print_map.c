/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:18:09 by apineda           #+#    #+#             */
/*   Updated: 2017/05/24 15:20:54 by apineda          ###   ########.fr       */
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

static	void	ft_save_up_down(t_map *m, t_piece *p)
{
	p->z_cnter = !p->z_cnter ? 1 : p->z_cnter;
	p->z_count = p->z_cnter;
	p->ret_col = m->col - p->col;
	p->ret_row = m->row - p->row;
	m->up = 0;
}

void			ft_save_ret(t_map *m, t_piece *p)
{
	if (p->z_cnter > p->z_count)
	{
		p->z_count = p->z_cnter;
		p->ret_col = m->col - p->col;
		p->ret_row = m->row - p->row;
		m->up = 0;
	}
	else if (m->up == 1 && !p->z_cnter && p->row == p->real_height - 1 &&
			p->col == p->real_width - 1)
		ft_save_up_down(m, p);
	else if (m->up == -1 && !p->z_cnter && p->row == p->save_row &&
			p->col == p->save_col)
		ft_save_up_down(m, p);
	else if (m->up != 0 && p->ret_col == -1 && p->ret_row == -1)
	{
		p->ret_col = m->col - p->col;
		p->ret_row = m->row - p->row;
	}
}

void			ft_rev_place_piece(t_map *m, t_piece *p)
{
	m->row = m->height - 1;
	p->ret_row = -1;
	p->ret_col = -1;
	p->z_count = 0;
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
	p->ret_row == -1 && p->ret_col == -1 ?
		ft_printf("0 0\n") : ft_printf("%d %d\n", p->ret_row, p->ret_col);
	ft_arraydel(p->piece, p->real_height);
	ft_arraydel(m->map, m->height);
}
