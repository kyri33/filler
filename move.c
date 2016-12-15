/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:11:49 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/12 16:57:42 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_piece(t_env *e, int y_i, int x_i)
{
	int	intersect;
	int	y;
	int	x;
	int	x_c;

	intersect = 0;
	y = 0;
	while (y < e->piece_h && y_i < e->map_h)
	{
		x = 0;
		x_c = x_i;
		while (x < e->piece_w && x_c < e->map_w)
		{
			if (e->piece[y][x] == '*' && e->map[y_i][x_c] != '.')
				intersect++;
			if (intersect == 2)
				return (0);
			x++;
			x_c++;
		}
		y++;
		y_i++;
	}
	return (1);
}

int	print_move(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	return (1);
}

int	place_piece(t_env *e, int y_i, int x_i)
{
	int	y;
	int	x;
	int	x_c;
	int	y_c;

	y = 0;
	while (y < e->piece_h)
	{
		x = 0;
		while (x < e->piece_w)
		{
			if (e->piece[y][x] == '*')
			{
				x_c = x_i - x;
				y_c = y_i - y;
				if (x_c >= 0 && y_c >= 0 && x_c + e->piece_w - 1 < e->map_w &&
					y_c + e->piece_h - 1 < e->map_h &&
					check_piece(e, y_c, x_c))
					return (print_move(y_i - y, x_i - x));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	make_move(t_env *e)
{
	int	y;
	int	x;

	y = 0;
	while (y < e->map_h)
	{
		x = 0;
		while (x < e->map_w)
		{
			if (e->map[y][x] == e->my_char)
				if (place_piece(e, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
