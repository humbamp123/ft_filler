/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zone_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:36:45 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 20:46:33 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void	ft_surround(t_map *m)
{
	int		tmp_i;
	int		tmp_j;

	m->row_counter = m->row ? 3 : 2;
	tmp_i = m->row ? m->row - 1 : m->row;
	while (tmp_i < m->height && m->row_counter > 0)
	{
		m->col_counter = m->col ? 3 : 2;
		tmp_j = m->col ? m->col - 1 : m->col;
		while (tmp_j < m->width && m->col_counter > 0)
		{
			if (!ft_isalpha(m->map[tmp_i][tmp_j]) &&
					!ft_isdigit(m->map[tmp_i][tmp_j]))
				m->map[tmp_i][tmp_j] = m->layer_num + '0';
			m->col_counter--;
			tmp_j++;
		}
		m->row_counter--;
		tmp_i++;
	}
}

static void	ft_zone_score(t_map *m)
{
	m->row = 0;
	while (m->row < m->height)
	{
		m->col = 0;
		while (m->col < m->width)
		{
			if (ft_isalnum(m->map[m->row][m->col]) &&
				m->map[m->row][m->col] != m->player &&
				m->map[m->row][m->col] != m->layer_num + '0')
				ft_surround(m);
			m->col++;
		}
		m->row++;
	}
}

static void	ft_zone_enemy(t_map *m)
{
	m->layer_counter = 0;
	m->layer_num = 0;
	while (m->layer_counter < 9)
	{
		if (m->layer_counter < 3)
			m->layer_num++;
		else
			m->layer_num--;
		ft_zone_score(m);
		m->layer_counter++;
	}
}

void		ft_zone_map(t_map *m)
{
	m->row = 0;
	while (m->row < m->height)
	{
		m->col = 0;
		while (m->col < m->width)
		{
			ft_tolower(m->map[m->row][m->col]);
			m->col++;
		}
		m->row++;
	}
	ft_zone_enemy(m);
}
