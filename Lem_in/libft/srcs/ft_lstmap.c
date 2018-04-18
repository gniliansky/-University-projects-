/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:08:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/13 19:03:42 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((new = f(lst)) == NULL)
		return (NULL);
	start = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (start);
}
