/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 09:46:52 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/24 09:47:43 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	data;

	ft_clear_data(&data);
	while (1)
	{
		if (ft_make_data(&data) == 0)
			break ;
		if (ft_check_position(&data) == 0)
			break ;
	}
	return (0);
}
