/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:46:31 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 13:46:33 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_change_position(t_room *head, char *name, int id)
{
	while (head)
	{
		if (ft_strcmp(head->name, name) == 0)
			if (head->position == -2)
			{
				head->position = id;
				return (1);
			}
		head = head->next;
	}
	return (0);
}

static void		ft_add_to_steck(t_connect_room **steck, char *name)
{
	t_connect_room	*new;
	t_connect_room	*end;

	end = *steck;
	new = malloc(sizeof(t_connect_room));
	new->next_room = ft_strdup(name);
	new->next = NULL;
	while (end->next)
		end = end->next;
	end->next = new;
}

static void		ft_add_name_steck(t_room *head, t_connect_room **steck)
{
	char			*name;
	t_room			*find;
	t_connect_room	*found;
	t_connect_room	*del;

	del = *steck;
	name = (*steck)->next_room;
	find = ft_find_ctruct_name(name, head);
	found = find->connect_room;
	while (found)
	{
		if (ft_change_position(head, found->next_room, find->position + 1) == 1)
			ft_add_to_steck(steck, found->next_room);
		found = found->next;
	}
	*steck = (*steck)->next;
	free(del->next_room);
	free(del);
}

void			ft_find_way(t_room *head)
{
	t_connect_room	*steck;
	t_room			*start;

	start = ft_find_ctruct_start(head);
	steck = malloc(sizeof(t_connect_room));
	steck->next_room = ft_strdup(start->name);
	steck->next = NULL;
	while (steck)
	{
		ft_add_name_steck(head, &steck);
	}
	ft_check_finish_way(head);
}
