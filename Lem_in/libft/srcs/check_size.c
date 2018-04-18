/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:05:56 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 18:06:17 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_size_minus(intmax_t *value, t_print *buf, va_list arg)
{
	char c;
	char a;

	a = buf->index;
	c = buf->size;
	if (c == 'H' && a != 'D')
		*value = (char)va_arg(arg, int);
	else if (c == 'h' && a != 'D')
		*value = (short)va_arg(arg, int);
	else if (c == 'l' || a == 'D')
		*value = va_arg(arg, long int);
	else if (c == 'L')
		*value = va_arg(arg, long long int);
	else if (c == 'j')
		*value = va_arg(arg, intmax_t);
	else if (c == 'z')
		*value = va_arg(arg, size_t);
	else
		*value = va_arg(arg, int);
	if (*value == 0 && (buf->index == 'x' || buf->index == 'X'))
		buf->grille = 0;
}

void	ft_check_size_plus(uintmax_t *value, t_print *buf, va_list arg)
{
	char c;
	char a;

	a = buf->index;
	c = buf->size;
	if (c == 'H' && a != 'O' && a != 'U')
		*value = (unsigned char)va_arg(arg, int);
	else if (c == 'h' && a != 'O' && a != 'U')
		*value = (unsigned short)va_arg(arg, int);
	else if (c == 'l' || a == 'O' || a == 'U')
		*value = va_arg(arg, unsigned long int);
	else if (c == 'L')
		*value = va_arg(arg, unsigned long long int);
	else if (c == 'j')
		*value = va_arg(arg, uintmax_t);
	else if (c == 'z')
		*value = va_arg(arg, size_t);
	else
		*value = va_arg(arg, unsigned int);
	if (*value == 0 && (buf->index == 'x' || buf->index == 'X'))
		buf->grille = 0;
}
