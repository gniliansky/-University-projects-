/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:32:19 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/14 10:18:46 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *begin_list)
{
	t_list *last;

	if (begin_list == NULL)
		return (NULL);
	else
	{
		last = begin_list;
		while (last->next != NULL)
		{
			last = last->next;
		}
	}
	return (last);
}
