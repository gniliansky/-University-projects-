/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:27:59 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/13 16:56:26 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	size_t i;

	if (*alst == NULL || del == NULL)
		return ;
	i = 0;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
