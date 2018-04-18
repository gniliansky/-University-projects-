/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:57:36 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/16 15:09:53 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*buf;

	if (s != NULL)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i] != '\0')
		{
			while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
				j--;
			j++;
			len = ft_strlen(s + i) - ft_strlen(s + j);
			if ((buf = ft_strsub(s, i, len)) != NULL)
				return (buf);
		}
		if ((buf = ft_strnew(0)) != NULL)
			return (buf);
	}
	return (NULL);
}
