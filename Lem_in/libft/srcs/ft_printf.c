/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:34:58 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 11:31:31 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_index_end(const char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z'
	|| str[i] == '#' || str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
	str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
		{
			i++;
			continue;
		}
		return (i);
	}
	return (i);
}

int		ft_transformation(t_print *buf, va_list arg)
{
	int		count;

	count = 0;
	if (ft_check_addres(buf->index) == 1)
		count = ft_print_addres(buf, arg);
	else if (ft_check_char(buf->index) == 1)
		count = ft_print_char(buf, arg);
	else if (ft_check_number_minus(buf->index) == 1)
		count = ft_print_number_minus(buf, arg);
	else if (ft_check_number_plus(buf->index) == 1)
		count = ft_print_number_plus(buf, arg);
	else if (ft_check_string(buf->index) == 1)
		count = ft_print_string(buf, arg);
	else
		count = ft_print_bed_index(buf);
	return (count);
}

int		ft_putout(const char **format, va_list arg)
{
	int			count;
	int			index;
	char		*arr;
	t_print		*buf;

	count = 0;
	arr = NULL;
	buf = NULL;
	index = ft_index_end(*format);
	if ((*format)[index] == '\0')
		*format = *format + index;
	if (**format != '\0' && (arr = ft_strnew(index)))
		ft_strncpy(arr, (*format) + 1, index);
	if (**format != '\0' && arr && (buf = ft_add_index(arr, index - 1)))
	{
		free(arr);
		count = ft_transformation(buf, arg);
		*format = *format + (index + 1);
		if (buf != NULL)
			free(buf);
		buf = NULL;
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (format[0] != '%')
		{
			ft_putchar(format[0]);
			format++;
			count = count + 1;
		}
		else if (format[0] == '%')
			count = count + ft_putout(&format, arg);
	}
	va_end(arg);
	return (count);
}
