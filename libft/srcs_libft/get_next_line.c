/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/15 12:01:56 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_freeone(t_list **list, t_list *cur)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->content_size != cur->content_size && tmp->next->content_size
			!= cur->content_size && tmp != NULL)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		if (tmp->content_size != cur->content_size)
			tmp->next = cur->next;
		else
			*list = cur->next;
		cur->content_size = 0;
		ft_strdel(((char **)&(cur->content)));
		ft_memdel((void **)&cur);
	}
}

static t_list	*ft_currentfd(int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (tmp);
	if (!(tmp->content = ft_strnew(0)))
	{
		ft_memdel((void **)&tmp);
		return (NULL);
	}
	tmp->content_size = fd;
	ft_lstadd_first(list, tmp);
	return (tmp);
}

static char		*ft_strjoinfree(char *str, char **b)
{
	char	*new;

	if (!(new = ft_strjoin(str, *b)))
		ft_strdel(b);
	else
		ft_memset(*b, 0, BUFF_SIZE + 1);
	ft_strdel(&str);
	return (new);
}

static char		*ft_linecopy(char *str, int opt)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (opt == 1)
		if (!(new = ft_strsub(str, 0, i)))
			ft_strdel(&str);
	if (opt == 2)
	{
		if (str[i] != 0)
			j = i + 1;
		else
		{
			j = i;
			i--;
		}
		while (str[j] != 0)
			j++;
		new = ft_strsub(str, i + 1, j);
		ft_strdel(&str);
	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			*b;
	t_list			*cur;
	int				r;

	if (BUFF_SIZE <= 0 || (r = read(fd, "", 0)) == -1)
		return (-1);
	if (!(cur = ft_currentfd(fd, &list)))
		return (-1);
	if (!(b = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(ft_strchr(cur->content, '\n')) && (r = read(fd, b, BUFF_SIZE) > 0))
		if (!(cur->content = ft_strjoinfree(cur->content, &b)))
			return (-1);
	ft_strdel(&b);
	if (!(*line = ft_linecopy(cur->content, 1)))
		return (-1);
	if (r == 0 && *((char *)(cur->content)) == 0)
	{
		ft_freeone(&list, cur);
		return (0);
	}
	return ((cur->content = ft_linecopy(cur->content, 2)) ? 1 : -1);
}
