/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:14:55 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 12:16:01 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(int width, int minus, char **str)
{
	int		n;
	char	*arr;
	int		len;
	int		i;

	if (str == NULL || *str == NULL)
		return (NULL);
	i = ft_strlen(*str);
	i = (i != 0 ? i - 1 : i);
	n = width;
	len = (n < 0 ? -n : n);
	if (len > (int)ft_strlen(*str) && (arr = ft_strnew(len)))
	{
		arr = ft_memset(arr, 32, len);
		if (minus == 1 && **str != '\0')
			arr = ft_memcpy(arr, *str, ft_strlen(*str));
		if (minus == 0 && **str != '\0')
			while (i >= 0)
				arr[--len] = (*str)[i--];
		if (*str)
			free(*str);
		return (arr);
	}
	return (*str);
}

char	*ft_width_char(int width, int minus, char **str)
{
	int		n;
	char	*arr;
	int		len;
	int		i;

	if (str == NULL || *str == NULL)
		return (NULL);
	i = ft_strlen(*str);
	i = (i != 0 ? i - 1 : i);
	n = width;
	len = (n < 0 ? -n : n);
	if (len > (int)ft_strlen(*str) && (arr = ft_strnew(len)))
	{
		arr = ft_memset(arr, 32, len);
		if (minus == 1)
			arr = ft_memcpy(arr, *str, ft_strlen(*str));
		if (minus == 0)
			while (i >= 0)
				arr[--len] = (*str)[i--];
		if (*str)
			free(*str);
		return (arr);
	}
	return (*str);
}
