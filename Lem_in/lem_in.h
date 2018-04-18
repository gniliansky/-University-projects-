/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:35:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/01/29 18:35:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"

typedef struct	s_info
{
	char			*line;
	struct s_info	*next;
}				t_info;

typedef struct	s_connect_room
{
	char					*next_room;
	struct s_connect_room	*next;
}				t_connect_room;

typedef struct	s_room
{
	t_connect_room	*connect_room;
	char			*name;
	int				ants;
	int				id_room;
	int				coord_x;
	int				coord_y;
	int				position;
	int				r_position;
	int				id_ant;
	struct s_room	*prev;
	struct s_room	*next;
}				t_room;

/*
**	(read_output.c)
*/

void			ft_read_output(t_room **head, t_info **info);

/*
**	(creat_roms.c)
*/

void			ft_create_rooms(char *str, t_room **head, int *valid_id);
t_room			*ft_create_new_room(void);
void			ft_add_coord_room_tool(t_room **head, int x, int y, char *name);

/*
**	(create_rooms_links.c)
*/

void			ft_add_data_link(char *first_room, t_room **head);

/*
**	(create_rooms_data.c)
*/

void			ft_add_data_room(char *str, t_room **head);

/*
**	(tools.c)
*/

void			ft_put_error(char *str);
void			ft_perror(void);
void			ft_put_info(t_info *info);
int				ft_isdigit_str(char *str);
int				ft_isprint_str(char *str);

/*
**	(validation.c)
*/

int				ft_validation(char *line, int *valid_id);

/*
**	(find_way.c)
*/

void			ft_find_way(t_room *head);

/*
**	(struct_tools.c)
*/

t_room			*ft_find_ctruct_name(char *name, t_room *head);
t_room			*ft_find_ctruct_start(t_room *head);
t_room			*ft_find_ctruct_end(t_room *head);

/*
**	(put_way.c)
*/

void			ft_put_way(t_room *head);

/*
**	(info.c)
*/

void			ft_save_info(char *line, t_info **info);

/*
**	(info.c)
*/

void			ft_check_finish_way(t_room *head);

#endif
