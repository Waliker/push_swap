/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idDuU_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:07:48 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:02:30 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		u_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[0] = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 10);
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}

int		d_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[0] = 0;
	ft_signedint(ap, arg);
	if ((*arg).stock[0] == '-')
	{
		(*arg).flags[1] = '-';
		i = 1;
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

int		bigd_arg(t_arg *arg, va_list ap)
{
	(*arg).conv[0] = 'l';
	return (d_arg(arg, ap));
}

int		bigu_arg(t_arg *arg, va_list ap)
{
	(*arg).conv[0] = 'l';
	return (u_arg(arg, ap));
}

int		b_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	(*arg).flags[0] = 0;
	(*arg).flags[1] = 0;
	(*arg).flags[2] = 0;
	ft_unsignedint(ap, arg, 2);
	ft_putflagsnb(arg);
	while (i < (int)(*arg).type_len)
		ft_putbuffer(arg, (*arg).stock[i++]);
	if ((*arg).flags[4] == '-')
		ft_putfield(arg, ' ', 1);
	ft_strdel(&(*arg).stock);
	ft_argreset(arg);
	return (1);
}
