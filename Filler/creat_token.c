/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:24:33 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/26 16:24:36 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_add_clear_lines_token(char **map, int x, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		if ((map[i] = ft_strnew(x)))
		{
			ft_memset(map[i], '.', x);
		}
		i++;
	}
}

static char		**ft_creat_clear_token(char *line)
{
	char	**map;
	int		size_y;
	int		size_x;
	int		i;

	i = 0;
	map = NULL;
	while ((line[i] < '0' || line[i] > '9') && line[i])
		i++;
	size_y = ft_atoi(line + i);
	while ((line[i] >= '0' && line[i] <= '9') && line[i])
		i++;
	size_x = ft_atoi(line + i);
	if ((map = malloc(sizeof(char*) * (size_y + 1))))
	{
		map[size_y] = NULL;
		ft_add_clear_lines_token(map, size_x, size_y);
	}
	return (map);
}

char			**ft_creat_token(char *string)
{
	char	**token;
	char	*line;
	int		i;
	int		y;

	if ((token = ft_creat_clear_token(string)))
	{
		y = 0;
		while (token[y])
		{
			i = 0;
			if (get_next_line(0, &line) > 0)
			{
				while (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
					i++;
				ft_put_line_sign(token, line + i, y);
				y++;
				if (line)
					free(line);
				line = NULL;
			}
		}
	}
	return (token);
}
