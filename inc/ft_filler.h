/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:11:14 by apineda           #+#    #+#             */
/*   Updated: 2017/05/21 00:24:28 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libft/includes/libft.h"

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
	char			player;
	int				height;
	int				width;
	char			**map;
}					t_map;

void				ft_zone_map(t_map *m);
void				ft_save_piece(t_piece *p);

#endif