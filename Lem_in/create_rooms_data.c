/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:36:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 18:36:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_valid_name_room(char *str, t_room **head)
{
	t_room		*find;

	find = *head;
	while (find)
	{
		if (find->name && ft_strcmp(str, find->name) == 0)
			ft_put_error("ft_valid_name_room");
		find = find->next;
	}
}

static void		ft_valid_coord_room(int x, int y, t_room **head)
{
	t_room		*find;

	find = *head;
	while (find)
	{
		if (find->coord_x == x && find->coord_y == y && find->name)
			ft_put_error("ft_valid_coord_room");
		find = find->next;
	}
}

static void		ft_add_coord_room(char *str, t_room **head)
{
	char	*coord_x;
	char	*coord_y;

	if (!str || !head)
		ft_put_error("ft_add_coord_room");
	coord_x = ft_strdup(ft_strchr(str, ' ') + 1);
	coord_y = ft_strdup(ft_strchr(coord_x, ' ') + 1);
	*(ft_strchr(coord_x, ' ')) = '\0';
	*(ft_strchr(str, ' ')) = '\0';
	ft_valid_name_room(str, head);
	ft_valid_coord_room(ft_atoi(coord_x), ft_atoi(coord_y), head);
	if ((((*head)->position == -1 || (*head)->position == 0))
		&& (*head)->coord_x == -30456)
	{
		(*head)->name = ft_strdup(str);
		(*head)->coord_x = ft_atoi(coord_x);
		(*head)->coord_y = ft_atoi(coord_y);
	}
	else
		ft_add_coord_room_tool(head, ft_atoi(coord_x),
								ft_atoi(coord_y), ft_strdup(str));
	free(coord_x);
	free(coord_y);
}

static void		ft_check_start_end(char *str, t_room **head)
{
	t_room		*find;
	int			id;
	t_room		*new;

	find = *head;
	id = (str[2] == 'e' ? -1 : 0);
	while (find)
	{
		if (find->position == id)
			ft_put_error("ft_check_start_end");
		find = find->next;
	}
	new = ft_create_new_room();
	if (ft_strcmp(str, "##end") == 0)
	{
		new->position = -1;
		new->r_position = 0;
	}
	else
	{
		new->position = 0;
		new->r_position = -1;
	}
	new->next = *head;
	*head = new;
}

void			ft_add_data_room(char *str, t_room **head)
{
	if (str[0] == '#' && str[1] != '#')
		return ;
	else if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str, "##start") != 0 && ft_strcmp(str, "##end") != 0)
			return ;
		else if (ft_strcmp(str, "##end") == 0 || ft_strcmp(str, "##start") == 0)
		{
			ft_check_start_end(str, head);
		}
	}
	else
		ft_add_coord_room(str, head);
}
