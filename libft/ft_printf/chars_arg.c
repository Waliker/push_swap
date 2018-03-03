/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sScCpct_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:07:58 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:42:11 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nullstr_arg(t_arg *arg)
{
	int		i;

	i = 0;
	(*arg).stock = "(null)";
	(*arg).type_len = ft_strlen((*arg).stock);
	if ((*arg).precision == 0)
		(*arg).type_len = 0;
	ft_putflagstring(arg);
	if ((*arg).flags[4] != '-')
		while (i < (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).stock[i++]);
	ft_argreset(arg);
	return (1);
}

int		s_arg(t_arg *arg, va_list ap)
{
	int		i;

	i = 0;
	if ((*arg).conv[0] == 'l')
		return (bigs_arg(arg, ap));
	if ((*arg).flags[3] == 0)
		(*arg).flags[3] = ' ';
	(*arg).stock = (char *)va_arg(ap, char *);
	if ((*arg).stock == NULL)
		return (ft_nullstr_arg(arg));
	(*arg).type_len = ft_strlen((*arg).stock);
	if ((*arg).precision == 0)
		(*arg).type_len = 0;
	ft_putflagstring(arg);
	if ((*arg).flags[4] != '-')
		while (i < (int)(*arg).type_len)
			ft_putbuffer(arg, (*arg).stock[i++]);
	ft_argreset(arg);
	return (1);
}

int		c_arg(t_arg *arg, va_list ap)
{
	size_t			type_len;

	type_len = 1;
	if ((*arg).conv[0] == 'l')
		return (bigc_arg(arg, ap));
	(*arg).typearg.c = (char)va_arg(ap, int);
	ft_putflagschar(arg, type_len);
	ft_putbuffer(arg, (*arg).typearg.c);
	if ((*arg).flags[4] == '-')
		while ((int)type_len < (*arg).minfield--)
			ft_putbuffer(arg, ' ');
	ft_argreset(arg);
	return (1);
}

int		pct_arg(t_arg *arg)
{
	char	c;

	(*arg).type = '%';
	if ((*arg).flags[3] != 0)
		c = (*arg).flags[3];
	else
		c = ' ';
	if ((*arg).minfield > 0 && (*arg).flags[4] != '-')
		while ((*arg).minfield-- - 1 > 0)
			ft_putbuffer(arg, c);
	ft_putbuffer(arg, '%');
	if ((*arg).minfield > 0 && (*arg).flags[4] == '-')
		while ((*arg).minfield-- - 1 > 0)
			ft_putbuffer(arg, c);
	ft_argreset(arg);
	return (1);
}
