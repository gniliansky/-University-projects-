/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:34:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 18:34:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_check_link(t_room *find, char *second_room)
{
	t_connect_room	*new;

	new = find->connect_room;
	while (new)
	{
		if (ft_strcmp(new->next_room, second_room) == 0)
			return (0);
		new = new->next;
	}
	return (1);
}

static void		ft_add_first_connect(char *first_room,
								char *second_room, t_room **head)
{
	t_room			*find;
	t_connect_room	*new;

	find = *head;
	while (find)
	{
		if (find->name && ft_strcmp(find->name, second_room) == 0)
		{
			if (ft_check_link(find, first_room) == 1)
			{
				new = malloc(sizeof(t_connect_room));
				new->next_room = ft_strdup(first_room);
				new->next = find->connect_room;
				find->connect_room = new;
			}
			return ;
		}
		find = find->next;
	}
	ft_put_error("ft_add_first_connect");
}

void			ft_add_data_link(char *first_room, t_room **head)
{
	char			*second_room;
	t_room			*find;
	t_connect_room	*new;

	new = NULL;
	second_room = NULL;
	find = *head;
	second_room = ft_strdup(ft_strchr(first_room, '-') + 1);
	*(ft_strchr(first_room, '-')) = '\0';
	while (find && find->name)
	{
		if (ft_strcmp(find->name, first_room) == 0)
		{
			ft_check_link(find, second_room);
			ft_add_first_connect(first_room, second_room, head);
			new = malloc(sizeof(t_connect_room));
			new->next_room = second_room;
			new->next = find->connect_room;
			find->connect_room = new;
			return ;
		}
		find = find->next;
	}
	ft_put_error("ft_add_data_link");
}
