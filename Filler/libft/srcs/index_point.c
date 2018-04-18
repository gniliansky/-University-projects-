/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:39:34 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/13 14:39:40 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_point_nbr_minus(t_print *buf, char *str)
{
	char	*arr;

	arr = NULL;
	if (buf == NULL && str == NULL)
		return (NULL);
	if (buf->point > 0 && buf->point_index == 1)
	{
		arr = ft_width(buf->point, 0, &str);
		ft_put_zero(buf->point_index, arr);
		if (buf->point >= (int)ft_strlen(str))
			arr = ft_add_plus_point(buf, arr);
		if (buf->point < (int)ft_strlen(str))
			arr = ft_add_plus(buf, arr);
		return (arr);
	}
	if (buf->point <= 0 && buf->point_index == 1)
	{
		if (str[0] == '0' && str[1] == '\0')
			str[0] = '\0';
		arr = ft_add_plus(buf, str);
		arr = ft_width(buf->point, 1, &arr);
		return (arr);
	}
	return (str);
}

char	*ft_point_nbr(t_print *buf, char *str)
{
	char	*arr;

	arr = NULL;
	if (buf == NULL && str == NULL)
		return (NULL);
	if (buf->point > 0 && buf->point_index == 1)
	{
		arr = ft_width(buf->point, 0, &str);
		ft_put_zero_adress(buf->point_index, arr);
		return (arr);
	}
	if (buf->point <= 0 && buf->point_index == 1)
	{
		if (str[0] == '0' && str[1] == '\0')
			str[0] = '\0';
		arr = ft_width(buf->point, 1, &str);
		ft_put_zero_adress(buf->point_index, arr);
		return (arr);
	}
	return (str);
}

char	*ft_point_str(t_print *buf, char *str)
{
	char	*arr;

	arr = NULL;
	if (buf == NULL && str == NULL)
		return (NULL);
	if (buf->point > 0 && buf->point_index == 1)
	{
		arr = ft_strsub(str, 0, buf->point);
		return (arr);
	}
	if (buf->point <= 0 && buf->point_index == 1)
	{
		arr = ft_strnew(-(buf->point));
		arr = ft_memset(arr, 32, -(buf->point));
		return (arr);
	}
	return (ft_strdup(str));
}
