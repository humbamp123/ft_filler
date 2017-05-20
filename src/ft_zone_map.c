/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zone_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:36:45 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 15:28:51 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void	ft_surround(t_map *m)
{
	int		tmp_i;
	int		tmp_j;

	m->k = 3;
	tmp_i = m->i ? m->i - 1 : m->i;
	while (tmp_i < m->h && m->k > 0)
	{
		m->l = 3;
		tmp_j = m->j ? m->j - 1 : m->j;
		while (tmp_j < m->w && m->l > 0)
		{
			// ft_dprintf(2, "w = %d h = %d\n", m->w, m->h);
			// ft_dprintf(2, "x = %d y = %d, char = %c\n", tmp_j, tmp_i, m->map[tmp_i][tmp_j]);
			if (!ft_isalpha(m->map[tmp_i][tmp_j]) && !ft_isdigit(m->map[tmp_i][tmp_j]))
				m->map[tmp_i][tmp_j] = m->z + '0';

			m->l--;
			tmp_j++;
			// ft_dprintf(2, "l = %d tmpj = %d\n", m->l, tmp_j);
		}
		m->k--;
		tmp_i++;
		// ft_dprintf(2, "k = %d h = %d\n", m->k, tmp_i);
	}
}

static void	ft_zone_score(t_map *m)
{
	m->i = 0;
	while (m->i < m->h)
	{
		m->j = 0;
		while (m->j < m->w)
		{
			if (ft_isalnum(m->map[m->i][m->j]) && (m->map[m->i][m->j] != m->player) && m->map[m->i][m->j] != m->z + '0')
			{
				// ft_dprintf(2, "here = %d and = %d", m->i, m->j);
				ft_surround(m);
			}
			m->j++;
		}
		m->i++;
	}
}

static void	ft_zone_enemy(t_map *m)
{
	m->x = 0;
	m->z = 0;
	while (m->x < 5)
	{
		if (m->x < 3)
			m->z++;
		else
			m->z--;
		ft_zone_score(m);
		m->x++;
		// ft_dprintf(2, "here = %d and = %d", m->x, m->z);
	}
}

void		ft_zone_map(t_map *m)
{
	m->i = 0;
	while (m->i < m->h)
	{
		m->j = 0;
		while (m->j < m->w)
		{
			if (m->map[m->i][m->j] == '.')
				m->map[m->i][m->j] = '/';
			else
				m->map[m->i][m->j] = ft_tolower(m->map[m->i][m->j]);
			m->j++;
		}
		m->i++;
	}
	ft_zone_enemy(m);
}