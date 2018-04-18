/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:52:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/01/30 14:52:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_valid_room_tool(char *copy, char *coord_x, char *coord_y)
{
	if (ft_strchr(copy, ' '))
	{
		coord_x = ft_strdup(ft_strchr(copy, ' ') + 1);
		if (ft_strchr(coord_x, ' '))
		{
			coord_y = ft_strdup(ft_strchr(coord_x, ' ') + 1);
			if (ft_isdigit_str(coord_y) == 0)
				ft_put_error("ft_valid_room_tool");
		}
		else
			ft_put_error("ft_valid_room_tool");
		*(ft_strchr(coord_x, ' ')) = '\0';
		if (ft_isdigit_str(coord_x) == 0)
			ft_put_error("ft_valid_room_tool");
		*(ft_strchr(copy, ' ')) = '\0';
		if (ft_isprint_str(copy) == 0)
			ft_put_error("ft_valid_room_tool");
		free(copy);
		free(coord_x);
		free(coord_y);
		return (1);
	}
	free(copy);
	return (0);
}

static void		ft_valid_room(char *line, int *valid_id)
{
	if (line[0] == '#')
		return ;
	else if (line[0] != 'L' && line[0] != '\t' && line[0] != ' ')
	{
		if ((ft_valid_room_tool(ft_strdup(line), NULL, NULL)) == 1)
			return ;
	}
	else if (line[0] == 'L' || line[0] == '\t' || line[0] == ' ')
		ft_put_error("ft_valid_room");
	*valid_id = 3;
}

static int		ft_valid_link(char *first_room)
{
	char *second_room;

	second_room = NULL;
	if (ft_strchr(first_room, '-'))
	{
		second_room = ft_strdup(ft_strchr(first_room, '-') + 1);
		*(ft_strchr(first_room, '-')) = '\0';
		if (ft_isprint_str(second_room) != 0 && ft_isprint_str(first_room) != 0)
		{
			free(first_room);
			free(second_room);
			return (1);
		}
	}
	free(first_room);
	return (0);
}

int				ft_validation(char *line, int *valid_id)
{
	if (*valid_id == 2)
		ft_valid_room(line, valid_id);
	if (*valid_id == 3)
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0
							&& ft_strcmp(line, "##end") != 0)
			return (1);
		if (line[0] != 'L' && line[0] != '\t' && line[0] != ' ')
			if (ft_valid_link(ft_strdup(line)) != 0)
				return (1);
		return (0);
	}
	if (*valid_id == 1)
	{
		if (line[0] == '#' && ft_strcmp(line, "##start") != 0
							&& ft_strcmp(line, "##end") != 0)
			return (1);
		if (ft_isdigit_str(line) != 0 && line[0] != '\0')
			return (1);
		return (0);
	}
	return (1);
}
