/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:16:47 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 09:17:04 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ITOA "0123456789abcdef"

static int		ft_nbr_len(intmax_t n, int base)
{
	int			i;
	uintmax_t	nbr;

	nbr = (n < 0 ? -n : n);
	i = (n <= 0 ? 1 : 0);
	while (nbr > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static void		ft_put_number(char *str, intmax_t value, int base)
{
	int			len;
	char		*arr;
	uintmax_t	n;

	n = (value < 0 ? -value : value);
	arr = ITOA;
	len = ft_nbr_len(value, base) - 1;
	if (value == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = arr[n % base];
		n = n / base;
		len--;
	}
	if (value < 0)
		str[len] = '-';
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char *str;

	if ((str = ft_strnew(ft_nbr_len(value, base))))
	{
		ft_put_number(str, value, base);
		return (str);
	}
	return (NULL);
}
