/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:45:47 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/10 09:32:03 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buf;

	i = 0;
	if (s != NULL && (buf = (char*)malloc(ft_strlen(s) + 1)) != NULL)
	{
		while (s[i])
		{
			buf[i] = f(i, s[i]);
			i++;
		}
		buf[i] = '\0';
		return (buf);
	}
	return (NULL);
}
