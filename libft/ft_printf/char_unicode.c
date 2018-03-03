/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:45:34 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:44:16 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	bigc_nosetlocal_arg(t_arg *arg)
{
	if ((*arg).typearg.wc < 0 || (*arg).typearg.wc > 255)
		return (-1);
	ft_putflagschar(arg, (*arg).type_len);
	ft_putbuffer(arg, (char)(*arg).typearg.wc);
	if ((*arg).flags[4] == '-')
		while ((int)(*arg).type_len < (*arg).minfield--)
			ft_putbuffer(arg, ' ');
	ft_argreset(arg);
	return (1);
}

int			bigc_arg(t_arg *arg, va_list ap)
{
	unsigned int	a;

	(*arg).type_len = 1;
	(*arg).typearg.wc = va_arg(ap, wint_t);
	if (MB_CUR_MAX == 1)
		return (bigc_nosetlocal_arg(arg));
	if ((*arg).typearg.wc < 0 || ((*arg).typearg.wc >= 0xd800
				&& (*arg).typearg.wc <= 0xdfff))
		return (-1);
	a = ft_itowchar((*arg).typearg.wc, &(*arg).type_len);
	if ((int)(*arg).type_len > MB_CUR_MAX)
		return (-1);
	ft_putflagschar(arg, (*arg).type_len);
	ft_putwchar(a, (int)(*arg).type_len, arg);
	if ((*arg).flags[4] == '-')
		while ((int)(*arg).type_len < (*arg).minfield--)
			ft_putbuffer(arg, ' ');
	ft_argreset(arg);
	return (1);
}
