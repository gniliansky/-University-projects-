/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:54:22 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/07 11:09:38 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			len;
	int				i;
	size_t			len_all;

	len_all = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	if (ft_strlen(dst) + 1 == dstsize)
		return (ft_strlen(src) + dstsize - 1);
	if ((ft_strlen(dst) + 1) >= dstsize)
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst);
	while (len < dstsize && src[i])
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	while (len < dstsize)
	{
		dst[len] = '\0';
		len++;
	}
	dst[len - 1] = '\0';
	return (len_all);
}
