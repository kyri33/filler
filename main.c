/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:47:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/12 16:55:21 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_freemap(t_env *e)
{
	int	y;

	y = 0;
	while (y < e->map_h)
	{
		free(e->map[y]);
		y++;
	}
	free(e->map);
}

int		malloc_map(t_env *e)
{
	char	**line;
	int		y;

	y = 0;
	line = ft_strsplit(gnl_until("Plateau"), ' ');
	e->map_h = ft_atoi(line[1]);
	e->map_w = ft_atoi(line[2]);
	if (!(e->map = (char **)malloc(sizeof(char**) * e->map_h)))
		return (0);
	while (y < e->map_h)
	{
		if (!(e->map[y] = (char *)malloc(sizeof(char*) * e->map_w)))
			return (0);
		y++;
	}
	return (1);
}

char	*gnl_until(char *str)
{
	char	*line;
	int		found;

	found = 0;
	while (found == 0 && get_next_line(0, &line) != -1)
	{
		if (ft_strstr(line, str) != NULL)
			found = 1;
	}
	return (line);
}

int		main(void)
{
	t_env	e;

	e.my_turn = 1;
	e.my_char = 'O';
	if (ft_strstr(gnl_until("$$$"), "p1") == NULL)
	{
		e.my_turn = 0;
		e.my_char = 'X';
	}
	if (malloc_map(&e))
		begin_game(&e);
	return (0);
}
