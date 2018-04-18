/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:14:23 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/19 15:14:25 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *s)
{
	int		count;
	char	*str;

	count = 0;
	if ((str = ft_strnew(4 + 1)))
	{
		while (*s)
		{
			count = count + ft_wcrtomb(str, *s);
			s++;
		}
		free(str);
	}
	return (count);
}

char	*ft_strunicode(int len, wchar_t *s)
{
	char	*arr;
	char	*buff;
	int		i;

	i = 0;
	if ((arr = ft_strnew(len + 1)))
		if ((buff = ft_strnew(5)))
		{
			while (len >= 0 && s[i])
			{
				len = len - ft_wcrtomb(buff, s[i]);
				if (len >= 0)
					ft_strcat(arr, buff);
				ft_strclr(buff);
				i++;
			}
			free(buff);
			return (arr);
		}
	return (NULL);
}
