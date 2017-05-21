/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:08:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 21:06:21 by andres           ###   ########.fr       */
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
	m->height = ft_atoi(array[1]);
	m->width = ft_atoi(array[2]);
	ft_arraydel(array);
	ft_strdel(&str);
}

static void			ft_read_map(t_map *m)
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
	map->row = 0;
	// printf("%d\n", map->h);
	while (map->row < map->height)
	{
		ft_dprintf(2, "%d: %s\n", map->row, map->map[map->row]);
		map->row++;
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
