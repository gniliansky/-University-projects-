/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:35:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/01/29 18:35:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_create_new_room(void)
{
	t_room		*new;

	new = malloc(sizeof(t_room));
	new->connect_room = NULL;
	new->name = NULL;
	new->ants = 0;
	new->id_room = -1;
	new->coord_x = -30456;
	new->coord_y = -47891;
	new->position = -2;
	new->r_position = -2;
	new->id_ant = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			ft_add_coord_room_tool(t_room **head, int x, int y, char *name)
{
	t_room	*new;

	new = ft_create_new_room();
	new->name = name;
	new->coord_x = x;
	new->coord_y = y;
	new->next = *head;
	*head = new;
}

static void		ft_add_data_number(char *str, t_room **head, int *valid_id)
{
	int			x;
	t_room		*new;

	new = NULL;
	if (str[0] != '#')
	{
		new = ft_create_new_room();
		x = ft_atoi(str);
		if (x > 0 && x <= 2147483647)
		{
			new->ants = x;
			*valid_id = 2;
		}
		else
			ft_put_error("ft_add_data_number");
		*head = new;
	}
}

void			ft_create_rooms(char *str, t_room **head, int *valid_id)
{
	if (!str || !head)
		ft_put_error("ft_create_rooms");
	if (str[0] == '#' && ft_strcmp(str, "##start") != 0
						&& ft_strcmp(str, "##end") != 0)
		return ;
	if (*valid_id == 1)
		ft_add_data_number(str, head, valid_id);
	else if (*valid_id == 2)
		ft_add_data_room(str, head);
	else if (*valid_id == 3)
		ft_add_data_link(str, head);
}
