/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:00:27 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/25 09:00:31 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_filler
{
	char		**map;
	int			map_x;
	int			map_y;
	char		**token;
	char		player;
	char		bad_player;
	int			g_x;
	int			g_y;
	t_coord		b_coor;
	int			b_result;
	int			connection;
}				t_filler;

/*
**	(data.c)
*/
int				ft_make_data(t_filler *data);
void			ft_clear_data(t_filler *data);
char			who_i_am(char *line, t_filler *data);
/*
**	(creat_map.c)
*/
char			**ft_creat_map(char *string, t_filler *data);
void			ft_put_line_sign(char **map, char *line, int y);
/*
**	(creat_token.c)
*/
char			**ft_creat_token(char *string);
/*
**	(check_position.c)
*/
int				ft_check_position(t_filler *data);
/*
**	(check_connection.c)
*/
int				ft_check_connection(t_filler *data, int y, int x);
/*
**	(tools.c)
*/
void			ft_printarr(char **arr);
char			**ft_free_arr(char **str);

#endif
