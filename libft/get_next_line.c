/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:30:41 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/09 15:51:06 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_stock(char **stock, char **line)
{
	char			*tmp;
	static int		count;

	if (*stock)
	{
		if ((tmp = ft_strchr(*stock, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(*stock);
			free(*stock);
			*stock = ft_strdup(tmp + 1);
			tmp = NULL;
			return (1);
		}
	}
	else if (count == 0)
	{
		*stock = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		count = 1;
	}
	return (0);
}

static int	check_read(char **stock, char *str, char **line, int index)
{
	char	*tmp;

	str[index] = '\0';
	if ((tmp = ft_strchr(str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, str);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(str);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stock;
	char		*str;
	int			index;

	if (check_stock(&stock, line))
		return (1);
	str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((index = read(fd, str, BUFF_SIZE)) > 0)
	{
		if (check_read(&stock, str, line, index))
			return (1);
		stock = ft_strjoin(stock, str);
	}
	free(str);
	str = NULL;
	if (index == -1)
		return (-1);
	if (ft_strlen(stock) > 0)
	{
		*line = ft_strdup(stock);
		free(stock);
		stock = NULL;
		return (1);
	}
	return (0);
}
