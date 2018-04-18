/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:03:19 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/25 09:03:21 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_make_data(t_filler *data)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
			data->player = who_i_am(line, data);
		else if (ft_strncmp(line, "Plateau", 7) == 0)
			data->map = ft_creat_map(line, data);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			data->token = ft_creat_token(line);
			free(line);
			return (1);
		}
		if (line)
			free(line);
		line = NULL;
	}
	return (0);
}

void	ft_clear_data(t_filler *data)
{
	data->map = NULL;
	data->map_x = 0;
	data->map_y = 0;
	data->token = NULL;
	data->player = 0;
	data->bad_player = 0;
	data->g_x = -1;
	data->g_y = -1;
	data->b_coor.x = 0;
	data->b_coor.y = 0;
	data->b_result = 10000;
	data->connection = 0;
}

char	who_i_am(char *line, t_filler *data)
{
	int		i;
	int		player;

	i = 0;
	player = 0;
	while ((line[i] < '0' || line[i] > '9') && line[i])
		i++;
	player = ft_atoi(line + i);
	if (player == 1)
	{
		data->bad_player = 'x';
		return ('O');
	}
	data->bad_player = 'o';
	return ('X');
}
