/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:53:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/01/30 10:53:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_check_start_finish_tool(t_room *find, int *start, int *end)
{
	if (find->position == 0)
	{
		if (find->coord_x != -30456)
			*start = *start + 1;
		else
			ft_put_error("ft_check_start_finish_tool");
	}
	if (find->position == -1)
	{
		if (find->coord_x != -30456)
			*end = *end + 1;
		else
			ft_put_error("ft_check_start_finish_tool");
	}
}

static void		ft_put_ants_start(t_room **head)
{
	t_room *start;
	t_room *end;
	t_room *prew;

	start = *head;
	end = *head;
	while (end->next)
	{
		prew = end;
		end = end->next;
	}
	while (start->position != 0)
		start = start->next;
	start->ants = end->ants;
	start->id_ant = 1;
	prew->next = NULL;
	free(end);
}

static void		ft_check_start_finish(t_room **head)
{
	int		start;
	int		end;
	t_room	*find;

	start = 0;
	end = 0;
	find = *head;
	while (find)
	{
		ft_check_start_finish_tool(find, &start, &end);
		find = find->next;
	}
	if (end != 1 || start != 1)
		ft_put_error("ft_check_start_finish");
	ft_put_ants_start(head);
}

void			ft_read_output(t_room **head, t_info **info)
{
	char	*line;
	int		valid_id;
	int		error;

	line = NULL;
	valid_id = 1;
	while (valid_id != -1 && (error = get_next_line(0, &line)) != 0)
	{
		if (error == -1)
			ft_perror();
		if (ft_validation(line, &valid_id) == 1)
		{
			ft_save_info(line, info);
			ft_create_rooms(line, head, &valid_id);
			if (line)
				free(line);
			line = NULL;
		}
		else
			valid_id = -1;
		if (line)
			free(line);
		line = NULL;
	}
	ft_check_start_finish(head);
}
