/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:43:39 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/10 11:57:06 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *buf;

	if (s1 != NULL && s2 != NULL &&
			(buf = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
	{
		ft_strcpy(buf, s1);
		ft_strcat(buf, s2);
		return (buf);
	}
	return (NULL);
}
