/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:46:05 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/13 11:30:16 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	if (c < 0 || c > 127)
		return (NULL);
	a = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == a)
		return ((char*)(s + i));
	return (NULL);
}
