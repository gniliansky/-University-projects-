/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:10:55 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/10 11:43:14 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buf;

	if ((buf = ft_strnew(len)) != NULL && s != NULL)
	{
		ft_strncpy(buf, s + start, len);
		return (buf);
	}
	return (NULL);
}
