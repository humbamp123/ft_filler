/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:34:24 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 19:35:27 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void		ft_print_map(t_map m)
{
	ft_dprintf(2, "\n\n\n");
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
}
