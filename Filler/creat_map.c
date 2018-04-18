/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 08:58:29 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/25 08:58:36 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_add_clear_lines(char **map, int x, int y)
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

static char		**ft_creat_clear_map(char *line, t_filler *data)
{
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	while ((line[i] < '0' || line[i] > '9') && line[i])
		i++;
	data->map_y = ft_atoi(line + i);
	while ((line[i] >= '0' && line[i] <= '9') && line[i])
		i++;
	data->map_x = ft_atoi(line + i);
	if ((map = malloc(sizeof(char*) * (data->map_y + 1))))
	{
		map[data->map_y] = NULL;
		ft_add_clear_lines(map, data->map_x, data->map_y);
	}
	return (map);
}

void			ft_put_line_sign(char **map, char *line, int y)
{
	int i;

	i = 0;
	if (map && *map && line)
	{
		while (line[i])
		{
			map[y][i] = line[i];
			i++;
		}
	}
}

char			**ft_creat_map(char *string, t_filler *data)
{
	char	**arr;
	char	*line;
	int		i;
	int		y;

	arr = NULL;
	if (data->map == NULL)
		if ((arr = ft_creat_clear_map(string, data)) == NULL)
			return (NULL);
	if (get_next_line(0, &line) > 0)
		free(line);
	y = 0;
	while (arr[y])
	{
		i = 0;
		if (get_next_line(0, &line) > 0)
		{
			while (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
				i++;
			ft_put_line_sign(arr, line + i, y++);
			free(line);
			line = NULL;
		}
	}
	return (arr);
}
