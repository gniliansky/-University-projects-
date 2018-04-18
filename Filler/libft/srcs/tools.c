/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:08:43 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/08 18:09:04 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_zerox_add(char *str, char a)
{
	char	*arr;

	arr = NULL;
	if (str)
	{
		if ((arr = ft_strnew(ft_strlen(str) + 2)))
		{
			arr[0] = '0';
			arr[1] = a;
			if (a == 'p')
				arr[1] = 'x';
			ft_strcpy(arr + 2, str);
		}
		return (arr);
	}
	return (str);
}

char			*ft_add_zerox(char *str, char a)
{
	char	*arr;

	arr = NULL;
	if (str && (a == '0' || a == 'x' || a == 'X' || a == 'p'))
	{
		if (a == '0')
		{
			if (str[0] != '0')
				if ((arr = ft_strnew(ft_strlen(str) + 1)))
				{
					arr[0] = '0';
					ft_strcpy(arr + 1, str);
				}
			if (str[0] == '0')
				return (str);
		}
		else
			arr = ft_add_zerox_add(str, a);
		if (str)
			free(str);
		return (arr);
	}
	return (str);
}

void			ft_str_toupper(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
}

int				ft_count_write(char **str)
{
	int	count;

	count = 0;
	if (*str != NULL)
	{
		count = ft_putstr_len(*str);
		free(*str);
	}
	*str = NULL;
	return (count);
}

int				ft_atoi_printf(const char *str)
{
	int					i;
	int					minus;
	unsigned long int	result;

	result = 0;
	minus = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = (minus == 0 ? result : -result);
	return (result);
}
