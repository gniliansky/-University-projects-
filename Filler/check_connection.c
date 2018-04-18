/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:42:11 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/26 16:42:13 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_tool_connection(t_filler *data, int y, int x)
{
	int result;

	result = 0;
	if ((x - 1) >= 0 && data->map[y][x - 1] == (data->bad_player - 32))
		result++;
	if (data->map[y][x + 1] != '\0' && data->map[y][x + 1] ==
											(data->bad_player - 32))
		result++;
	if ((y - 1) >= 0 && data->map[y - 1][x] == (data->bad_player - 32))
		result++;
	if (data->map[y + 1] && data->map[y + 1][x] == (data->bad_player - 32))
		result++;
	return (result);
}

static	void	ft_put_coor(t_filler *data, int y, int x, int count)
{
	data->connection = count;
	data->g_x = x;
	data->g_y = y;
}

int				ft_check_connection(t_filler *data, int y, int x)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (data->token[i])
	{
		j = 0;
		while (data->token[i][j])
		{
			if (data->token[i][j] == '*')
			{
				count = count + ft_tool_connection(data, i + y, j + x);
			}
			j++;
		}
		i++;
	}
	if (count > data->connection)
	{
		ft_put_coor(data, y, x, count);
		return (1);
	}
	return (0);
}
