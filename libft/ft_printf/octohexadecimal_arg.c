/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXoOp_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:26:35 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:59:12 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		o_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 8);
	if ((*arg).flags[0] != 0)
	{
		(*arg).minfield = (*arg).minfield - 1;
		if ((*arg).precision > 0)
			(*arg).precision--;
	}
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}

int		x_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 16);
	if ((*arg).stock[0] == 48)
		(*arg).flags[0] = 0;
	else if ((*arg).flags[0] != 0)
		(*arg).minfield = (*arg).minfield - 2;
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}

int		bigx_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 16);
	if ((*arg).stock[0] == 48)
		(*arg).flags[0] = 0;
	else if ((*arg).flags[0] != 0)
		(*arg).minfield = (*arg).minfield - 2;
	ft_strcapitalize((*arg).stock);
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}

int		bigo_arg(t_arg *arg, va_list ap)
{
	(*arg).conv[0] = 'l';
	return (o_arg(arg, ap));
}

int		p_arg(t_arg *arg, va_list ap)
{
	int		i;

	(*arg).conv[0] = 'j';
	(*arg).type = 'x';
	i = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 16);
	(*arg).flags[0] = '#';
	(*arg).minfield = (*arg).minfield - 2;
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}
