/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:44:25 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/10 15:06:55 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_len(char const *s)
{
	unsigned int len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		return (len);
	}
	return (-1);
}
