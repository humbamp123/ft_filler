/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:08:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/22 01:24:17 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int					g_turn;
int					g_player;

static	char		ft_player_check(char **str)
{
	ERR1(!ft_strncmp("$$$ exec p1", *str, 11), ft_strdel(str), 'o');
	ERR1(!ft_strncmp("$$$ exec p2", *str, 11), ft_strdel(str), 'x');
	return (0);
}

static	void		ft_map_size(t_map *m, char **str)
{
	char		**array;

	if (!*str || !**str)
		get_next_line(0, str);
	array = ft_strsplit(*str, ' ');
	m->height = ft_atoi(array[1]);
	m->width = ft_atoi(array[2]);
	ft_arraydel(array, 3);
	ft_strdel(str);
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
		ft_arraydel(array, 2);
	}
	m->map = map_cpy;
}

int					main(void)
{
	t_map		map;
	t_piece		piece;
	char		*str;

	g_player = 0;
	while (get_next_line(0, &str) > 0)
	{
		g_turn = g_turn ? 0 : 1;
		ft_bzero(&map, sizeof(t_map));
		ft_bzero(&piece, sizeof(t_piece));
		map.player = !g_player ? ft_player_check(&str) : g_player;
		g_player = map.player;
		if (!map.enemy)
			map.enemy = map.player == 'o' ? 'x' : 'o';
		ft_map_size(&map, &str);
		ft_read_map(&map);
		ft_save_piece(&piece, &str);
		piece.row = 0;
		while (piece.row < piece.height)
		{
			ft_dprintf(2, "%s%s%s\n", G, piece.piece[piece.row++], W);
		}
		ft_zone_map(&map);
		ft_print_map(map);
		ft_place_piece(&map, &piece);
	}
	return (0);
}
