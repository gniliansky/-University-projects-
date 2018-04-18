/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:52:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 16:52:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_add_info(char *line, t_info **info)
{
	t_info		*new;
	t_info		*end;

	new = NULL;
	end = *info;
	if ((new = malloc(sizeof(t_info))) == NULL)
		ft_perror();
	if ((new->line = ft_strdup(line)) == NULL)
		ft_perror();
	new->next = NULL;
	while (end->next)
		end = end->next;
	end->next = new;
}

void			ft_save_info(char *line, t_info **info)
{
	if (info == NULL || line == NULL)
		ft_put_error("ft_save_info");
	if (line[0] == '#' && line[1] == '#' && line[2] != '#')
		if (ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0)
			return ;
	if (*info == NULL)
	{
		if ((*info = malloc(sizeof(t_info))) == NULL)
			ft_perror();
		if (((*info)->line = ft_strdup(line)) == NULL)
			ft_perror();
		(*info)->next = NULL;
	}
	else
		ft_add_info(line, info);
}
