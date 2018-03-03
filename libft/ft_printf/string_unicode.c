/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:26:43 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:43:56 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_bigs_nosetlocal(t_arg *arg, int i)
{
	(*arg).type_len = i;
	i = 0;
	if ((*arg).precision >= 0 && (*arg).precision < (int)(*arg).type_len)
		(*arg).type_len = (*arg).precision;
	if ((*arg).flags[4] != '-')
		while (i++ < (*arg).minfield - (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).flags[3]);
	i = 0;
	while (i < (int)(*arg).type_len)
	{
		if ((*arg).typearg.ws[i] < 0 || (*arg).typearg.ws[i] > 255)
			return (-1);
		ft_putbuffer(arg, (char)(*arg).typearg.ws[i++]);
	}
	i = 0;
	if ((*arg).flags[4] == '-')
		while (i++ < (*arg).minfield - (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).flags[3]);
	ft_argreset(arg);
	return (1);
}

static int	ft_wstrlen(size_t *size, t_arg *arg)
{
	int		i;

	i = 0;
	while ((*arg).typearg.ws[i] != 0)
	{
		if ((*arg).typearg.ws[i] < 0 || ((*arg).typearg.ws[i] >= 0xd800
					&& (*arg).typearg.ws[i] <= 0xdfff))
		{
			ft_memdel((void **)&size);
			return (0);
		}
		ft_itowchar((wint_t)(*arg).typearg.ws[i], &size[i]);
		(*arg).type_len = size[i] + (*arg).type_len;
		i++;
	}
	return (1);
}

static void	ft_wstring_putfield(t_arg *arg, size_t *size)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if ((*arg).precision >= 0 && (*arg).precision < (int)(*arg).type_len)
	{
		while ((int)size[i] + len <= (*arg).precision)
			len = len + size[i++];
		(*arg).type_len = len;
		i = 0;
	}
	if ((*arg).flags[4] != '-')
		while (i++ < (*arg).minfield - (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).flags[3]);
}

static int	ft_putwstring(t_arg *arg, size_t *size)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((*arg).typearg.ws[i] != 0 && len != (int)(*arg).type_len)
	{
		if ((int)size[i] > MB_CUR_MAX)
		{
			ft_memdel((void **)&size);
			return (-1);
		}
		ft_putwchar(ft_itowchar((wint_t)(*arg).typearg.ws[i], &size[i]),
				size[i], arg);
		len = len + size[i];
		i++;
	}
	(*arg).type_len = len;
	i = 0;
	if ((*arg).flags[4] == '-')
		while (i++ < (*arg).minfield - (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).flags[3]);
	ft_memdel((void **)&size);
	return (1);
}

int			bigs_arg(t_arg *arg, va_list ap)
{
	int				i;
	size_t			*size;

	i = 0;
	if ((*arg).flags[3] == 0 || (*arg).flags[4] == '-')
		(*arg).flags[3] = ' ';
	(*arg).typearg.ws = (wchar_t *)va_arg(ap, wchar_t *);
	if ((*arg).typearg.ws == NULL)
		return (ft_nullstr_arg(arg));
	while ((*arg).typearg.ws[i] != 0)
		i++;
	if (MB_CUR_MAX == 1)
		return (ft_bigs_nosetlocal(arg, i));
	if (!(size = ft_memalloc(sizeof(size) * i)))
		exit(EXIT_FAILURE);
	if (!ft_wstrlen(size, arg))
		return (-1);
	ft_wstring_putfield(arg, size);
	if (!ft_putwstring(arg, size))
		return (-1);
	ft_argreset(arg);
	return (1);
}
