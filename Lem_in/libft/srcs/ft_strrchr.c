/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:11:55 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/07 11:45:02 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		x;
	char	a;

	if (c < 0 || c > 127)
		return (NULL);
	i = -1;
	x = 0;
	a = (char)c;
	while (s[x])
	{
		if (s[x] == a)
			i = x;
		x++;
	}
	if (i >= 0)
		return ((char*)(s + i));
	if (s[x] == a)
		return ((char*)(s + x));
	return (NULL);
}
