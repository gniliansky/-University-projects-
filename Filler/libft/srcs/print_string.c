/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:34:22 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 11:34:39 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(t_print *buf, va_list arg)
{
	int		count;
	char	c;
	char	*str;

	count = 0;
	str = NULL;
	c = (char)va_arg(arg, int);
	if (buf && c == '\0' && (str = ft_strnew(0)))
	{
		if (buf->minus == 1)
		{
			ft_putchar('\0');
			buf->width = buf->width - 1;
		}
		count = ft_formating_string_char(buf, &str) + 1;
		if (buf->minus == 0)
			ft_putchar('\0');
	}
	else if (buf && (str = ft_strnew(1)))
	{
		str[0] = c;
		count = ft_formating_string_char(buf, &str);
	}
	return (count);
}

int		ft_print_bed_index(t_print *buf)
{
	char	*str;
	int		count;

	str = NULL;
	count = 0;
	if (buf && (str = ft_strnew(1)))
	{
		str[0] = buf->index;
		count = ft_formating_string_char(buf, &str);
	}
	return (count);
}

int		ft_print_unicode(t_print *buf, va_list arg)
{
	wchar_t		*arr;
	int			count;
	char		*str;

	count = 0;
	arr = (wchar_t*)va_arg(arg, wchar_t*);
	if (arr == NULL)
		str = ft_strdup("(null)");
	else if (buf && buf->point_index == 0)
		str = ft_strunicode(ft_wstrlen(arr), arr);
	else if (buf && buf->point_index != 0)
		str = ft_strunicode(buf->point, arr);
	if (buf)
		count = ft_formating_string_char(buf, &str);
	return (count);
}

int		ft_print_string(t_print *buf, va_list arg)
{
	int		count;
	char	*str;

	str = NULL;
	count = 0;
	if (buf && (buf->index == 'S' || (buf->size == 'l' && buf->index == 's')))
		count = ft_print_unicode(buf, arg);
	else if (buf && buf->index == 's')
	{
		str = va_arg(arg, char*);
		if (str == NULL)
		{
			str = "(null)";
		}
		str = ft_point_str(buf, str);
		if (buf->point < 0)
			count = ft_count_write(&str);
		if (buf->point >= 0)
			count = ft_formating_string_char(buf, &str);
	}
	return (count);
}
