/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:21:45 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/14 20:12:33 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		countwords(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static	void	ft_free(char **arr, int j)
{
	while (--j <= 0)
	{
		free(arr[j]);
		arr[j] = NULL;
	}
	free(arr);
	arr = NULL;
}

static	void	ft_putwords(char **arr, char const *s, char c, int i)
{
	int j;
	int len;

	j = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				len++;
				i++;
			}
			if ((arr[j++] = ft_strsub(s, i - len, len)) == NULL)
			{
				ft_free(arr, j);
				return ;
			}
			len = 0;
		}
	}
	arr[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (s != NULL)
	{
		if ((arr = (char**)malloc(sizeof(char*) *
						(countwords(s, c) + 1))) != NULL)
		{
			ft_putwords(arr, s, c, i);
			if (arr != NULL)
				return (arr);
		}
	}
	return (NULL);
}
