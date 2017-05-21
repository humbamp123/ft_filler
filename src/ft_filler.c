/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:08:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 11:32:13 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	char		ft_player_check(void)
{
	char		*str;

	str = NULL;
	get_next_line(0, &str);
	ERR1(!ft_strncmp("$$$ exec p1", str, 11), ft_strdel(&str), 'o');
	ERR1(!ft_strncmp("$$$ exec p2", str, 11), ft_strdel(&str), 'x');
	ft_strdel(&str);
	return (0);
}

static	void		ft_map_size(t_map *m)
{
	char		**array;
 	char		*str;

	str = NULL;
	get_next_line(0, &str);
	array = ft_strsplit(str, ' ');
	m->height = ft_atoi(array[1]);
	m->width = ft_atoi(array[2]);
	ft_arraydel(array);
	ft_strdel(&str);
}

static	void		ft_read_map(t_map *m)
{
	char	*str;
	char	**array;
	char	**map_cpy;

	m->row = 0;
	get_next_line(0, &str);
	ft_strdel(&str);
	map_cpy = (char **)ft_memalloc(sizeof(char *) * m->height);
	while (m->row < m->height)
	{
		get_next_line(0, &str);
		array = ft_strsplit(str, ' ');
		ft_strdel(&str);
		map_cpy[m->row++] = ft_strdup(array[1]);
		ft_arraydel(array);
	}
	m->map = map_cpy;
}

static	void		ft_print_map(t_map m)
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
			else if (m.map[m.row][m.col] > '3')
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

int					main(void)
{
	char		*str;
	char		**array;
	t_map		*map;
	t_piece		*piece;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	map->player = !map->player ? ft_player_check() : map->player;
	if (!map->enemy)
		map->enemy = map->player == 'o' ? 'x' : 'o';
	ft_map_size(map);
	ft_read_map(map);
	ft_zone_map(map);
	ft_print_map(*map);
	ft_save_piece(piece);
	ft_place_piece(map, piece);
	ft_dprintf(1, "%d %d\n", piece->ret_x, piece->ret_y);
	ft_arraydel(piece->piece);
	ft_arraydel(map->map);
	free(piece);
	free(map);
	return (0);
}
