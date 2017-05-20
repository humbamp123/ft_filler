/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:08:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 22:03:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	int		ft_player_check(char *str)
{
	get_next_line(0, &str);
	ERR1(!ft_strncmp("$$$ exec p1", str, 11), ft_strdel(&str), 'o');
	ERR1(!ft_strncmp("$$$ exec p2", str, 11), ft_strdel(&str), 'x');
	ft_strdel(&str);
	return (0);
}

int				main(void)
{
	char		*str;
	char		**array;
	t_map		*map;

	str = NULL;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->player = ft_player_check(str);
	map->
	// while (get_next_line(0, &str) > 0)
	// {
	// 	ERR((array = ft_strsplit(str, ' ')) == NULL, -1);
	// 	ft_insert_row(map, array);
	// 	map->y_cnt++;
	// 	ft_arraydel(array);
	// 	ft_strdel(&str);
	// }
	free(map);
	return (0);
}