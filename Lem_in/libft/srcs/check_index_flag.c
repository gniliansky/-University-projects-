/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:07:35 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/07 16:08:04 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_number_plus(char a)
{
	if (a == 'o' || a == 'O' || a == 'u' || a == 'U' || a == 'x' || a == 'X')
		return (1);
	return (0);
}

int		ft_check_number_minus(char a)
{
	if (a == 'd' || a == 'D' || a == 'i')
		return (1);
	return (0);
}

int		ft_check_char(char a)
{
	if (a == 'c' || a == 'C')
		return (1);
	return (0);
}

int		ft_check_string(char a)
{
	if (a == 's' || a == 'S')
		return (1);
	return (0);
}

int		ft_check_addres(char a)
{
	if (a == 'p')
		return (1);
	return (0);
}
