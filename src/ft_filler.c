/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:08:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 15:41:12 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	char		ft_player_check()
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
	m->h = ft_atoi(array[1]);
	m->w = ft_atoi(array[2]);
	ft_arraydel(array);
}

static void			ft_read_map(t_map *m)
{
	char	*str;
	char	**array;
	char	**mapcpy;

	m->i = 0;
	get_next_line(0, &str);
	ft_strdel(&str);
	mapcpy = (char **)ft_memalloc(sizeof(char *) * m->h);
	while (m->i < m->h)
	{
		get_next_line(0, &str);
		array = ft_strsplit(str, ' ');
		ft_strdel(&str);
		mapcpy[m->i++] = ft_strdup(array[1]);
		ft_arraydel(array);
	}
	m->map = mapcpy;
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
	ft_map_size(map);
	ft_read_map(map);
	ft_zone_map(map);
	ft_save_piece(piece);
	map->i = 0;
	// printf("%d\n", map->h);
	while (map->i < map->h)
	{
		ft_dprintf(2, "%d: %s\n", map->i, map->map[map->i]);
		map->i++;
	}
	// ft_dprintf(2, "height = %d, width = %d\n", map->h, map->w);
	// while (get_next_line(0, &str) > 0)
	// {
	// 	ERR((array = ft_strsplit(str, ' ')) == NULL, -1);
	// 	ft_insert_row(map, array);
	// 	map->y_cnt++;
	// 	ft_arraydel(array);
	// 	ft_strdel(&str);
	// }
	ft_arraydel(map->map);
	free(map);
	return (0);
}