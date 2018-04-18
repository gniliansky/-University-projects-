/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:51:56 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/11 10:47:36 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbrlen(int n)
{
	int				i;
	unsigned int	nbr;

	nbr = (n < 0 ? -n : n);
	i = (n <= 0 ? 1 : 0);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static	void	ft_arrey(char *arr, int n)
{
	unsigned int nbr;
	unsigned int i;

	if (arr == NULL)
		return ;
	i = 0;
	if (n == 0)
	{
		arr[i] = '0';
		return ;
	}
	nbr = (n < 0 ? -n : n);
	while (nbr > 0)
	{
		arr[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	if (n < 0)
	{
		arr[i] = '-';
		i++;
	}
}

static void		strrev(char *arr)
{
	unsigned int	i;
	unsigned int	len;
	char			a;

	i = 0;
	len = ft_strlen(arr) - 1;
	while (i < len)
	{
		a = arr[i];
		arr[i] = arr[len];
		arr[len] = a;
		i++;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char *arr;

	if ((arr = ft_strnew(nbrlen(n))) != NULL)
	{
		ft_arrey(arr, n);
		strrev(arr);
		return (arr);
	}
	return (NULL);
}
