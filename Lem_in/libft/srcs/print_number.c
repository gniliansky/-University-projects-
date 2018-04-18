/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:02:53 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 11:03:15 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_number_minus(t_print *buf, va_list arg)
{
	int			count;
	intmax_t	value;
	char		*str;

	str = NULL;
	count = 0;
	if (buf)
	{
		ft_check_size_minus(&value, buf, arg);
		if ((str = ft_itoa_base(value, 10)))
			if ((str = ft_point_nbr_minus(buf, str)))
			{
				if (buf->point >= 0)
					count = ft_formating_string_minus(buf, &str);
				if (buf->point < 0)
					count = ft_count_write(&str);
			}
	}
	return (count);
}

int		ft_print_number_plus(t_print *buf, va_list arg)
{
	int			count;
	uintmax_t	value;
	char		*str;

	str = NULL;
	count = 0;
	if (buf)
	{
		ft_check_size_plus(&value, buf, arg);
		if (buf->index == 'o' || buf->index == 'O')
			str = ft_itoa_base_plus(value, 8);
		else if (buf->index == 'x')
			str = ft_itoa_base_plus(value, 16);
		else if (buf->index == 'X')
		{
			str = ft_itoa_base_plus(value, 16);
			ft_str_toupper(str);
		}
		else
			str = ft_itoa_base_plus(value, 10);
		if (str)
			count = ft_formating_string_plus(buf, &str);
	}
	return (count);
}

int		ft_print_addres(t_print *buf, va_list arg)
{
	int			count;
	uintmax_t	x;
	char		*str;

	str = NULL;
	count = 0;
	if (buf)
	{
		x = va_arg(arg, uintmax_t);
		if ((str = ft_itoa_base_plus(x, 16)))
		{
			if (buf->point < 0)
				if ((str = ft_add_zerox(str, 'x')))
					if ((str = ft_point_nbr(buf, str)))
						count = ft_count_write(&str);
			if (buf->point >= 0)
				if ((str = ft_point_nbr(buf, str)))
					if ((str = ft_add_zerox(str, 'x')))
						count = ft_formating_string_plus(buf, &str);
		}
	}
	return (count);
}
