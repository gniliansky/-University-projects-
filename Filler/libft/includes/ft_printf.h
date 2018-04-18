/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:41:22 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/07 11:50:45 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_print
{
	int		grille;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		point;
	int		point_index;
	int		width;
	char	size;
	char	index;
}				t_print;

/*
**	Main function
**	(ft_printf.c)
*/

/*
**	Create a structure for flags and fill it
**	(add_flags.c)
*/
t_print			*ft_add_index(char *buf, int index);
/*
**	Check the specifier and size of it
**	(check_size.c)
*/
void			ft_check_size_minus(intmax_t *value, t_print *buf, va_list arg);
void			ft_check_size_plus(uintmax_t *value, t_print *buf, va_list arg);
/*
**	(check_index_flag.c)
*/
int				ft_check_number_plus(char a);
int				ft_check_number_minus(char a);
int				ft_check_char(char a);
int				ft_check_string(char a);
int				ft_check_addres(char a);
/*
**	Create a line, which will be changed
**	(print_string.c)
*/
int				ft_print_char(t_print *buf, va_list arg);
int				ft_print_bed_index(t_print *buf);
int				ft_print_unicode(t_print *buf, va_list arg);
int				ft_print_string(t_print *buf, va_list arg);
/*
**	(print_number.c)
*/
int				ft_print_number_minus(t_print *buf, va_list arg);
int				ft_print_number_plus(t_print *buf, va_list arg);
int				ft_print_addres(t_print *buf, va_list arg);
/*
**	Formatting a string using functions
**	(formating_string.c)
*/
int				ft_formating_string_addres(t_print *buf, char **str);
int				ft_formating_string_char(t_print *buf, char **str);
int				ft_formating_string_minus(t_print *buf, char **str);
int				ft_formating_string_plus(t_print *buf, char **str);
/*
**	Functions for line formatting
**	(index_point.c)
*/
char			*ft_point_nbr_minus(t_print *buf, char *str);
char			*ft_point_nbr(t_print *buf, char *str);
char			*ft_point_str(t_print *buf, char *str);
/*
**	(index_zero.c)
*/
void			ft_put_zero(int zero, char *str);
void			ft_put_zero_string(int zero, char *str, int minus);
void			ft_put_zero_adress(int zero, char *str);
/*
**	(index_width.c)
*/
char			*ft_width(int width, int minus, char **str);
char			*ft_width_char(int width, int minus, char **str);
/*
**	(index_plus.c)
*/
char			*ft_add_plus(t_print *buf, char *str);
char			*ft_add_plus_point(t_print *buf, char *str);
/*
**	(index_space.c)]
*/
char			*ft_space(t_print *buf, char *str);
/*
**	(index_grille.c)
*/
char			*ft_grille(t_print *buf, char *str);
/*
**	Other functions
**	(tools.c)
*/
char			*ft_add_zerox(char *str, char a);
void			ft_str_toupper(char *str);
int				ft_count_write(char **str);
int				ft_atoi_printf(const char *str);
/*
**(itoa_base_minus.c)
*/
char			*ft_itoa_base(intmax_t value, int base);
/*
**	(itoa_base_plus.c)
*/
char			*ft_itoa_base_plus(uintmax_t value, int base);
/*
**	(unicode.c)
*/
int				ft_wstrlen(wchar_t *s);
char			*ft_strunicode(int len, wchar_t *s);
/*
**	(ft_wcrtomb.c)
*/
size_t			ft_wcrtomb(char *s, wchar_t sign);

#endif
