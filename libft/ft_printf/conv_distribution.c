/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:13:36 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:04:06 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_conv_distribution(t_arg *arg, va_list ap)
{
	static int	(*conv_distrib[15])(t_arg*, va_list) = { &d_arg, &d_arg,
				&u_arg, &o_arg, &x_arg, &bigd_arg, &bigu_arg, &bigo_arg,
				&bigx_arg, &c_arg, &bigc_arg, &s_arg, &bigs_arg, &p_arg,
				&b_arg};
	char		*ptr_conv;
	int			i;

	ptr_conv = "diuoxDUOXcCsSpb";
	i = 0;
	while (i < 15)
	{
		if (ptr_conv[i] == (*arg).type)
			return (conv_distrib[i](arg, ap));
		i++;
	}
	(*arg).type_len = 1;
	if ((*arg).flags[3] == 0)
		(*arg).flags[3] = ' ';
	(*arg).stock = &(*arg).type;
	ft_putflagstring(arg);
	if ((*arg).flags[4] != '-')
		ft_putbuffer(arg, (*arg).stock[0]);
	ft_argreset(arg);
	return (1);
}
