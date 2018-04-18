/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:51:59 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 13:52:03 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ITOA "0123456789abcdef"

static int		ft_nbr_len_plus(uintmax_t nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		i = 1;
	while (nbr > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static void		ft_put_number_plus(char *str, uintmax_t value, int base)
{
	int			len;
	char		*arr;

	arr = ITOA;
	len = ft_nbr_len_plus(value, base) - 1;
	if (value == 0)
		str[0] = '0';
	while (value > 0)
	{
		str[len] = arr[value % base];
		value = value / base;
		len--;
	}
}

char			*ft_itoa_base_plus(uintmax_t value, int base)
{
	char *str;

	if ((str = ft_strnew(ft_nbr_len_plus(value, base))))
	{
		ft_put_number_plus(str, value, base);
		return (str);
	}
	return (NULL);
}
