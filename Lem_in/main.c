/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:54:49 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/06 18:54:51 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_room		*head;
	t_info		*info;

	head = NULL;
	info = NULL;
	ft_read_output(&head, &info);
	ft_find_way(head);
	ft_put_info(info);
	ft_put_way(head);
	return (0);
}
