/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:18:09 by apineda           #+#    #+#             */
/*   Updated: 2017/05/24 15:22:06 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int					g_player;

static	char		ft_player_check(char **str)
{
	ERR1(!ft_strncmp("$$$ exec p1", *str, 11), ft_strdel(str), 'O');
	ERR1(!ft_strncmp("$$$ exec p2", *str, 11), ft_strdel(str), 'X');
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
		ft_bzero(&map, sizeof(t_map));
		ft_bzero(&piece, sizeof(t_piece));
		map.player = !g_player ? ft_player_check(&str) : g_player;
		g_player = map.player;
		map.enemy = map.player == 'O' ? 'X' : 'O';
		ft_map_size(&map, &str);
		ft_read_map(&map);
		ft_save_piece(&piece, &str);
		ft_zone_map(&map);
		ft_print_map(map);
		if (map.player == 'O')
			map.up = map.height < 50 ? -1 : 1;
		else
			map.up = map.height < 50 ? 1 : -1;
		map.up == 1 ? ft_place_piece(&map, &piece) :
			ft_rev_place_piece(&map, &piece);
	}
	return (0);
}
