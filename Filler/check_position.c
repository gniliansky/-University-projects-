/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:05:37 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/25 09:05:40 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_put_good_coor(t_filler *data, int y, int x, t_coord g_coor)
{
	int		a;
	int		b;
	int		i;
	int		j;

	a = 0;
	b = 0;
	if (ft_check_connection(data, y, x) != 0 || data->connection != 0)
		return ;
	i = (data->b_coor).y;
	j = (data->b_coor).x;
	a = ((i - g_coor.y) >= 0 ? (i - g_coor.y) : -(i - g_coor.y));
	b = ((j - g_coor.x) >= 0 ? (j - g_coor.x) : -(j - g_coor.x));
	if (data->b_result > a + b)
	{
		data->g_y = y;
		data->g_x = x;
		data->b_result = a + b;
	}
}

static void		ft_check(t_filler *data, int y, int x, int result)
{
	int			i;
	int			j;
	t_coord		g_coor;

	i = -1;
	while (data->token[++i])
	{
		j = -1;
		while (data->token[i][++j])
			if (data->token[i][j] == '*')
			{
				g_coor.x = x + j;
				g_coor.y = y + i;
				if ((i + y) >= data->map_y || (x + j) >= data->map_x)
					return ;
				if (data->map[y + i][x + j] == data->player)
					result++;
				if (data->map[y + i][x + j] != '.' &&
								data->map[y + i][x + j] != data->player)
					return ;
			}
	}
	if (result == 1)
		ft_put_good_coor(data, y, x, g_coor);
}

static void		ft_put_bed_coor(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == (data->bad_player - 32))
			{
				(data->b_coor).x = j;
				(data->b_coor).y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int				ft_check_position(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
	ft_put_bed_coor(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_check(data, i, j, 0);
			j++;
		}
		i++;
	}
	data->map = ft_free_arr(data->map);
	data->map = NULL;
	data->token = ft_free_arr(data->token);
	ft_printf("%i %i\n", data->g_y, data->g_x);
	data->g_y = 0;
	data->g_x = 0;
	data->connection = 0;
	data->b_result = 10000;
	return (1);
}
