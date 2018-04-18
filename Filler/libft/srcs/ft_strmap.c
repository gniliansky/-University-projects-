/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:01:20 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/09 18:27:26 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*buf;

	i = 0;
	if (s != NULL && (buf = (char*)malloc(ft_strlen(s) + 1)) != NULL)
	{
		while (s[i])
		{
			buf[i] = f(s[i]);
			i++;
		}
		buf[i] = '\0';
		return (buf);
	}
	return (NULL);
}
