/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:28:54 by andres            #+#    #+#             */
/*   Updated: 2017/05/22 02:01:22 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	int		ft_zone_count(t_map *m, t_piece *p)
{
	int		i;
	int		j;

	i = m->row;
	p->check_row = -1;
	p->zone_count = 0;
	while (i < m->height && ++p->check_row < p->real_height)
	{
		p->check_col = -1;
		j = m->col;
		while (j < m->width && ++p->check_col < p->real_width)
		{
			if(ft_isdigit(m->map[i][j]) &&
					p->piece[p->check_row][p->check_col] == '*')
			{
				p->zone_count += m->map[i][j] - '0';
				// ft_dprintf(2, "zone count = %d, charnum = %d\n", p->zone_count, m->map[i][j] - '0');
			}
			j++;
		}
		i++;
	}
	// ft_dprintf(2, "zone count = %d", p->zone_count);
	return (p->zone_count);
}

static	int		ft_piece_check(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	// ft_dprintf(2 , "i = %d, height = %d, j = %d, width = %d, count = %d\n\n", p->check_row, p->real_height, p->check_col, p->real_width, p->count);
	ERR(m->row - p->row < 0, 0);
	ERR(m->col - p->col < 0, 0);
	i = m->row - p->row;
	p->check_row = -1;
	while (i < m->height && ++p->check_row < p->real_height)
	{
		j = m->col - p->col;
		p->check_col = -1;
		while (j < m->width && ++p->check_col < p->real_width)
		{
			if(m->map[i][j] == m->player &&
					p->piece[p->check_row][p->check_col] == '*')
				p->count++;
			ERR(m->map[i][j] == m->enemy &&
					p->piece[p->check_row][p->check_col] == '*', 0);
			ERR(p->count > 1, 0);
			j++;
		}
		i++;
		// ft_dprintf(2, "WHAT ARE YOU??? ===== %d\n", p->count);
	}
	// ft_dprintf(2 , "i = %d, height = %d, j = %d, width = %d, count = %d\n\n", p->check_row, p->real_height, p->check_col, p->real_width, p->count);
	ERR(p->check_row < p->real_height || p->check_col < p->real_width || p->count == 0, 0);
	// ft_dprintf(2, "COOOOOOOOOOOOOOL\n");
	return (1);
}

static	int		ft_piece_reject(t_piece *p)
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
	// ft_dprintf(2, "not rejected\n");
	return (1);
}

// static	void	ft_try_piece_here(t_map *m, t_piece *p)
// {
// 	p->row = p->save_row;
// 	while (p->row < p->real_height)
// 	{
// 		p->col = p->save_col;
// 		while (p->col < p->real_width)
// 		{
// 			if (p->piece[p->row][p->col] == '*' && !ft_piece_reject(m, p))
// 			{
// 			}
// 			else if (p->piece[p->row][p->col] == '*' && ft_piece_check(m, p)
// 						&& p->zone_count < ft_zone_count(m, p))
// 			{
// 				p->zone_count = ft_zone_count(m, p);
// 				p->ret_col = p->col - m->col;
// 				p->ret_row = p->row - m->row;
// 			}
// 			p->col++;
// 		}
// 		p->row++;
// 	}
// }

static	void	ft_try_piece_here(t_map *m, t_piece *p)
{
	p->row = p->save_row;
	while (p->row < p->real_height)
	{
		p->col = p->save_col;
		while (p->col < p->real_width)
		{
			p->count = 0;
			// ft_dprintf(2, "count = %d, row = %d, col = %d\n", ft_zone_count(m, p), p->row, p->col);
			// ft_dprintf(2, "m->row = %d, m->col = %d\n", m->row, m->col);
			// ft_dprintf(2, "yes? = %d, check? = %d, zonecount = %d > %d <-old? true? = %d\n", p->piece[p->row][p->col] == '*', ft_piece_check(m, p), ft_zone_count(m, p), p->zone_count, !p->zone_count);
			if (p->piece[p->row][p->col] == '*' && !ft_piece_reject(p))
			{
				// ft_dprintf(2, "NOTHING SHOUD BE HERE\n");
			}
			else if (p->piece[p->row][p->col] == '*' && ft_piece_check(m, p)
						&& (p->zone_count < ft_zone_count(m, p) || !p->zone_count))
			{
				// ft_dprintf(2, "HEREHEREHEREHEREHRErow = %d col = %d, p->piece = %c", p->row, p->col, p->piece[p->row][p->col]);
				p->zone_count = !ft_zone_count(m, p) ? 1 : ft_zone_count(m, p);
				p->ret_col = m->col - p->col;
				p->ret_row = m->row -p->row;
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
	// ft_dprintf(2, "real_width = %d", p->real_width);
	ft_printf("%d %d\n", p->ret_row, p->ret_col);
	ft_arraydel(p->piece, p->real_height);
	ft_arraydel(m->map, m->height);
}