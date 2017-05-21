/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:11:14 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 20:58:33 by andres           ###   ########.fr       */
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