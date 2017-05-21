/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:11:14 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 11:20:47 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef struct		s_piece
{
	int				height;
	int				width;
	int				row;
	int				col;
	int				flag;
	int				savex;
	int				savey;
	int				real_width;
	int				real_height;
	int				zone_count;
	int				count;
	int				ret_x;
	int				ret_y;
	int				checkx;
	int				checky;
	char			**piece;

}					t_piece;

typedef struct		s_map
{
	int				row;
	int				col;
	int				row_counter;
	int				col_counter;
	int				layer_counter;
	int				layer_num;
	int				zone_max;
	char			player;
	char			enemy;
	int				height;
	int				width;
	char			**map;
}					t_map;

void				ft_zone_map(t_map *m);
void				ft_save_piece(t_piece *p);
void				ft_place_piece(t_map *map, t_piece *p);

#endif