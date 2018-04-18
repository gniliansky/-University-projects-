/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:40:17 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/30 13:51:17 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				ft_add(char buf[], char **str, char **line)
{
	int		i;
	char	*s;

	i = 0;
	if ((s = ft_strnew(ft_strlen(buf))))
	{
		while (buf[i] && buf[i] != '\n')
		{
			s[i] = buf[i];
			i++;
		}
		s[i] = '\0';
		*str = ft_strdup(s);
		free(s);
		if (buf[i] == '\n')
		{
			buf = ft_strcpy(buf, buf + (i + 1));
			*line = *str;
			return (0);
		}
	}
	ft_bzero(buf, BUFF_SIZE);
	*line = *str;
	return (1);
}

static int				ft_connect(char buf[], char **str, char **line)
{
	int		i;
	char	*s;
	int		j;

	i = ft_strlen(*str);
	j = 0;
	if ((s = ft_strnew(ft_strlen(buf) + i)))
	{
		ft_strcpy(s, *str);
		while (buf[j] && buf[j] != '\n')
			s[i++] = buf[j++];
		s[i] = '\0';
		free(*str);
		*str = ft_strdup(s);
		free(s);
		if (buf[j] == '\n')
		{
			buf = ft_strcpy(buf, buf + (j + 1));
			*line = *str;
			return (0);
		}
	}
	ft_bzero(buf, BUFF_SIZE);
	*line = *str;
	return (1);
}

static	struct s_line	*ft_check_fd(struct s_line **head, int fd)
{
	struct s_line	*start;
	struct s_line	*new;

	if (head == NULL)
		return (NULL);
	start = *head;
	if (*head != NULL)
		while (start)
		{
			if (start->fd == fd)
				return (start);
			start = start->next;
		}
	if ((new = malloc(sizeof(struct s_line))))
	{
		new->finish = 0;
		new->next = NULL;
		new->fd = fd;
		ft_bzero(new->buf, BUFF_SIZE + 1);
		if (*head != NULL)
			new->next = *head;
		*head = new;
		return (new);
	}
	return (NULL);
}

static void				ft_delete_list(struct s_line **head,
	struct s_line **del)
{
	struct s_line **buf;

	if (head && *head && del && *del)
	{
		buf = head;
		if (*head == *del)
			*head = (*del)->next;
		else
		{
			while (*buf && (*buf)->next != *del)
			{
				*buf = (*buf)->next;
			}
			(*buf)->next = (*del)->next;
		}
		free(*del);
		del = NULL;
	}
}

int						get_next_line(const int fd, char **line)
{
	static struct s_line	*head = NULL;
	struct s_line			*l;
	char					*str;
	int						r;

	str = NULL;
	l = ft_check_fd(&head, fd);
	if (l->buf[0] != '\0')
		if (ft_add(l->buf, &str, line) == 0)
			return (1);
	while ((r = read(l->fd, l->buf, BUFF_SIZE)) != 0)
	{
		if (r == -1 || l->fd < 0 || line == NULL || l == NULL)
			return (-1);
		l->buf[r] = '\0';
		if ((str != NULL ? ft_connect(l->buf, &str, line)
			: ft_add(l->buf, &str, line)) == 0)
			return (1);
	}
	if (str != NULL && l->finish == 0)
		return (1);
	l->finish = 1;
	ft_delete_list(&head, &l);
	return (0);
}
