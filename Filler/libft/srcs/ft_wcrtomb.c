/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:10:25 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 14:10:44 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_save_one(char *s, unsigned int x)
{
	if (x != 0)
	{
		s[0] = (char)x;
		return (1);
	}
	return (0);
}

static int		ft_save_two(char *s, unsigned int x)
{
	s[1] = 128 | (char)(63 & x);
	s[0] = 192 | (char)(63 & (x >> 6));
	return (2);
}

static int		ft_save_three(char *s, unsigned int x)
{
	s[2] = 128 | (char)(63 & x);
	s[1] = 128 | (char)(63 & (x >> 6));
	s[0] = 224 | (char)(31 & (x >> 12));
	return (3);
}

static int		ft_save_four(char *s, unsigned int x)
{
	s[3] = 128 | (char)(63 & x);
	s[2] = 128 | (char)(63 & (x >> 6));
	s[1] = 128 | (char)(63 & (x >> 12));
	s[0] = 240 | (char)(15 & (x >> 18));
	return (4);
}

size_t			ft_wcrtomb(char *s, wchar_t sign)
{
	unsigned int	x;

	x = (unsigned int)sign;
	if (x <= 127)
		return (ft_save_one(s, x));
	else if (x <= 2047)
		return (ft_save_two(s, x));
	else if (x <= 65535)
		return (ft_save_three(s, x));
	else if (x >= 65536 && x <= 11141111)
		return (ft_save_four(s, x));
	return (-1);
}
