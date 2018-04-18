/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:42:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 13:42:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_find_ctruct_name(char *name, t_room *head)
{
	t_room	*find;

	find = head;
	while (find && ft_strcmp(find->name, name) != 0)
		find = find->next;
	return (find);
}

t_room	*ft_find_ctruct_start(t_room *head)
{
	t_room	*find;

	find = head;
	while (find && find->position != 0)
		find = find->next;
	return (find);
}

t_room	*ft_find_ctruct_end(t_room *head)
{
	t_room	*find;

	find = head;
	while (find && find->position != -1)
		find = find->next;
	return (find);
}
