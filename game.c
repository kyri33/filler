/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:05:19 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/12 17:19:19 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	populate_map(t_env *e)
{
	int		y;
	char	*line;
	int		x;
	char	**tab;

	y = 0;
	while (y < e->map_h)
	{
		get_next_line(0, &line);
		tab = ft_strsplit(line, ' ');
		x = 0;
		while (x < e->map_w)
		{
			e->map[y][x] = tab[1][x];
			x++;
		}
		y++;
	}
}

void	populate_piece(t_env *e)
{
	int		y;
	char	*line;
	int		x;

	y = 0;
	while (y < e->piece_h)
	{
		get_next_line(0, &line);
		x = 0;
		while (x < e->piece_w)
		{
			e->piece[y][x] = line[x];
			x++;
		}
		y++;
	}
}

void	free_piece(t_env *e)
{
	int	y;

	y = 0;
	while (y < e->piece_h)
	{
		free(e->piece[y]);
		e->piece[y] = NULL;
		y++;
	}
	free(e->piece);
	e->piece = NULL;
}

int		malloc_piece(t_env *e)
{
	char	**line;
	int		y;

	y = 0;
	line = ft_strsplit(gnl_until("Piece"), ' ');
	e->piece_h = ft_atoi(line[1]);
	e->piece_w = ft_atoi(line[2]);
	if (!(e->piece = (char **)malloc(sizeof(char**) * e->piece_h)))
		return (0);
	while (y < e->piece_h)
	{
		if (!(e->piece[y] = (char *)malloc(sizeof(char*) * e->piece_w)))
			return (0);
		y++;
	}
	return (1);
}

void	begin_game(t_env *e)
{
	if (e->my_turn)
	{
		gnl_until("0123456");
		populate_map(e);
	}
	else
	{
		e->my_turn = 1;
		gnl_until("01234");
		populate_map(e);
	}
	malloc_piece(e);
	populate_piece(e);
	if (!make_move(e))
	{
		print_move(0, 0);
		ft_freemap(e);
		exit(0);
	}
	free_piece(e);
	e->my_turn = 0;
	gnl_until("Plateau");
	begin_game(e);
}
