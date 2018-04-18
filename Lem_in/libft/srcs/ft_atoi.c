/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:07:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/11 16:34:03 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long int	result;

	result = 0;
	minus = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	minus = (str[i] == '-' ? 1 : 0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 8)) && minus == 1)
			return (0);
		else if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 7)) && minus == 0)
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = (minus == 0 ? result : -result);
	return (result);
}
