/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:31:37 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/04 12:18:45 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	char			*dup;
	unsigned int	len;

	len = 0;
	while (s1[len])
		len++;
	if ((dup = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	len = 0;
	while (s1[len])
	{
		dup[len] = s1[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
