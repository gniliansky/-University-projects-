/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:19:14 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 18:19:18 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_check_give_ants(t_room *start, t_room *name, t_room *head)
{
	t_room			*find;
	t_connect_room	*new;
	int				ants;

	new = start->connect_room;
	ants = start->ants;
	find = NULL;
	while (new)
	{
		find = ft_find_ctruct_name(new->next_room, head);
		if (find->r_position != -2 && find->r_position < name->r_position
											&& find->name != name->name)
			ants = ants - (name->r_position - find->r_position);
		new = new->next;
	}
	if (ants >= 0)
		return (1);
	return (0);
}

static void		ft_put_ants_start(t_room *start, t_room *end, t_room *head)
{
	if (end->r_position == 0)
	{
		ft_printf("L%i-%s ", start->id_ant, end->name);
		end->ants = end->ants + 1;
		start->id_ant = start->id_ant + 1;
		start->ants = start->ants - 1;
	}
	else if (start->ants)
	{
		if (ft_check_give_ants(start, end, head) == 0)
			return ;
		ft_printf("L%i-%s ", start->id_ant, end->name);
		end->id_ant = start->id_ant;
		start->id_ant = start->id_ant + 1;
		start->ants = start->ants - 1;
	}
}

static void		ft_put_ants(t_room *end, t_room *head)
{
	t_room	*prew;

	prew = end->prev;
	if (prew->prev && prew->id_ant != 0 && prew->position != 0)
	{
		ft_printf("L%i-%s ", prew->id_ant, end->name);
		end->id_ant = prew->id_ant;
		prew->id_ant = 0;
	}
	if (prew->prev && prew->position != 0)
		ft_put_ants(prew, head);
	else
		ft_put_ants_start(prew, end, head);
}

static void		ft_print_way_ants(t_connect_room *find,
								t_room *head, t_room *end)
{
	t_room	*prew;

	prew = ft_find_ctruct_name(find->next_room, head);
	if (prew->prev && prew->position != -2)
	{
		if (prew->id_ant != 0)
		{
			ft_printf("L%i-%s ", prew->id_ant, end->name);
			end->ants = end->ants + 1;
			prew->id_ant = 0;
		}
		if (prew->position != 0)
			ft_put_ants(prew, head);
	}
	if (prew->position == 0)
		ft_put_ants_start(prew, end, head);
}

void			ft_put_way(t_room *head)
{
	t_room				*end;
	t_connect_room		*find;
	int					start_ants;

	end = ft_find_ctruct_end(head);
	start_ants = ft_find_ctruct_start(head)->ants;
	while (end->ants != start_ants)
	{
		find = end->connect_room;
		while (find)
		{
			ft_print_way_ants(find, head, end);
			find = find->next;
		}
		ft_printf("\n");
	}
}
