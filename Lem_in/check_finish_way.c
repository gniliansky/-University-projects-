/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:01:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 18:01:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				ft_put_r_position(char *name, t_room *head, int id)
{
	t_room				*find;
	t_connect_room		*found;
	t_room				*prew;

	prew = NULL;
	find = ft_find_ctruct_name(name, head);
	found = find->connect_room;
	find->r_position = id;
	while (found)
	{
		prew = ft_find_ctruct_name(found->next_room, head);
		if (prew->position == (find->position - 1) &&
			prew->r_position == -2 && prew->prev == NULL)
		{
			find->prev = prew;
			ft_put_r_position(prew->name, head, id + 1);
			return ;
		}
		else if (prew->position == 0)
		{
			find->prev = prew;
			return ;
		}
		found = found->next;
	}
}

static void				ft_sort_connect_room_end_tools(t_connect_room **head,
															t_room *rooms)
{
	t_connect_room		*prew;
	t_connect_room		*start;
	t_connect_room		*next;

	prew = *head;
	start = (*head)->next;
	while (start && (next = start->next) && next->next)
	{
		if (ft_find_ctruct_name(start->next_room, rooms)->position >
			ft_find_ctruct_name(next->next_room, rooms)->position)
		{
			prew->next = next;
			start->next = next->next;
			next->next = start;
			prew = next;
			continue;
		}
		else
		{
			prew = start;
			start = next;
		}
	}
}

static int				ft_lenght_struct(t_connect_room *head)
{
	int		i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

static t_connect_room	*ft_sort_connect_room_end(t_connect_room **head,
														t_room *rooms)
{
	t_connect_room		*start;
	t_connect_room		*next;
	int					i;

	i = ft_lenght_struct(*head) + 1;
	while (i--)
		if (head && *head && (*head)->next)
		{
			next = (*head)->next;
			if (ft_find_ctruct_name((*head)->next_room, rooms)->position >
				ft_find_ctruct_name(next->next_room, rooms)->position)
			{
				start = *head;
				start->next = next->next;
				*head = next;
				next->next = start;
			}
			ft_sort_connect_room_end_tools(head, rooms);
		}
	return (*head);
}

void					ft_check_finish_way(t_room *head)
{
	t_connect_room	*find;
	int				finish;

	finish = 0;
	find = ft_sort_connect_room_end(&(ft_find_ctruct_end(head)->connect_room)
																	, head);
	while (find)
	{
		if (ft_find_ctruct_name(find->next_room, head)->position != -2
		&& ft_find_ctruct_name(find->next_room, head)->prev == NULL)
		{
			finish++;
			ft_put_r_position(find->next_room, head, 1);
		}
		find = find->next;
	}
	if (finish == 0)
		ft_put_error("ft_check_finish_way");
}
