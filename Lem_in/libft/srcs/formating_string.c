/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:18:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 18:18:26 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formating_string_addres(t_print *buf, char **str)
{
	int		count;

	count = 0;
	if (buf && str && *str)
	{
		if ((*str = ft_width(buf->width, buf->minus, str)))
		{
			if (buf->point_index == 0)
				ft_put_zero_adress(buf->zero, *str);
			count = ft_count_write(str);
		}
	}
	return (count);
}

int		ft_formating_string_char(t_print *buf, char **str)
{
	int		count;

	count = 0;
	if (buf && str && *str)
	{
		if (buf->point < 0 && (buf->index != 'S' || buf->index != 's'))
			buf->width = buf->point;
		if (buf->index == 'S' || buf->index == 's')
		{
			if ((*str = ft_width(buf->width, buf->minus, str)))
			{
				ft_put_zero_string(buf->zero, *str, buf->minus);
				count = ft_count_write(str);
			}
		}
		else
		{
			if ((*str = ft_width_char(buf->width, buf->minus, str)))
			{
				ft_put_zero_string(buf->zero, *str, buf->minus);
				count = ft_count_write(str);
			}
		}
	}
	return (count);
}

int		ft_formating_string_minus(t_print *buf, char **str)
{
	int		count;

	count = 0;
	if (buf && (*str = ft_add_plus(buf, *str)))
		if ((*str = ft_width(buf->width, buf->minus, str)))
		{
			if (buf->point_index == 0)
				ft_put_zero(buf->zero, *str);
			if ((*str = ft_space(buf, *str)))
				count = ft_count_write(str);
		}
	return (count);
}

int		ft_formating_string_plus(t_print *buf, char **str)
{
	int		count;

	count = 0;
	if (buf && buf->point < 0)
		if ((*str = ft_grille(buf, *str)))
			if ((*str = ft_point_nbr(buf, *str)))
				count = ft_count_write(str);
	if (buf && buf->point >= 0)
		if ((*str = ft_point_nbr(buf, *str)))
			if ((*str = ft_grille(buf, *str)))
				if ((*str = ft_width(buf->width, buf->minus, str)))
				{
					if (buf->point_index == 0)
						ft_put_zero_adress(buf->zero, *str);
					count = ft_count_write(str);
				}
	return (count);
}
