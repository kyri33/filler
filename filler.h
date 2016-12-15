/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:20:14 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/12 16:58:18 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_env
{
	int		my_turn;
	char	my_char;
	int		map_w;
	int		map_h;
	int		piece_w;
	int		piece_h;
	char	**map;
	char	**piece;
}				t_env;

char			*gnl_until(char *str);
void			ft_freemap(t_env *e);
void			begin_game(t_env *e);
int				make_move(t_env *e);
int				print_move(int y, int x);

#endif
