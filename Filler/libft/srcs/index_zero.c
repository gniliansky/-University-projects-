/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:24:21 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/12 14:24:25 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero(int zero, char *str)
{
	int		i;

	i = 0;
	if (str && zero == 1 && str[0])
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		{
			if (str[0] == '+' || str[0] == '-')
				break ;
			if (str[i] == '+')
				str[0] = '+';
			if (str[i] == '-')
				str[0] = '-';
			str[i++] = '0';
		}
	}
	return ;
}

void	ft_put_zero_string(int zero, char *str, int minus)
{
	int		i;

	i = 0;
	if (str && zero == 1 && minus == 0)
	{
		i = 0;
		while (str[i] == ' ')
		{
			str[i++] = '0';
		}
	}
	return ;
}

void	ft_put_zero_adress(int zero, char *str)
{
	int		i;

	i = 0;
	if (str && zero == 1)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == 'x' || str[i] == '0')
		{
			if (str[1] == 'x')
				break ;
			if (str[i] == 'x')
				str[1] = 'x';
			str[i++] = '0';
		}
	}
	return ;
}
