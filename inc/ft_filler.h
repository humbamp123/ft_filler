/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:11:14 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 23:58:43 by apineda          ###   ########.fr       */
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
	int				save_col;
	int				save_row;
	int				real_width;
	int				real_height;
	int				zone_count;
	int				count;
	int				ret_col;
	int				ret_row;
	int				check_col;
	int				check_row;
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
	int				zone_odd;
	int				zone_even;
	char			player;
	char			enemy;
	int				height;
	int				width;
	char			**map;
}					t_map;

void				ft_zone_map(t_map *m);
void				ft_save_piece(t_piece *p, char **str);
void				ft_place_piece(t_map *map, t_piece *p);
void				ft_print_map(t_map m);

#endif