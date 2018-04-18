/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:42:47 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/11 15:23:32 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && ((const unsigned char*)s1)[i]
			== ((const unsigned char*)s2)[i])
		i++;
	return (((const unsigned char*)s1)[i]
			- ((const unsigned char*)s2)[i]);
}
