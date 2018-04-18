/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:54:01 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/09 10:54:37 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	if (d <= s)
		ft_memcpy(d, s, len);
	else
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	return (dst);
}
