/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:11:14 by apineda           #+#    #+#             */
/*   Updated: 2017/05/20 15:42:16 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef struct		s_piece
{
	int				h;
	int				w;
	int				i;
	int				j;
	// int				k;
	// int				l;
	// int				x;
	// int				z;
}					t_piece;

typedef struct		s_map
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				x;
	int				z;
	char			player;
	int				h;
	int				w;
	char			**map;
	char			**zone;
}					t_map;

void				ft_zone_map(t_map *m);

#endif