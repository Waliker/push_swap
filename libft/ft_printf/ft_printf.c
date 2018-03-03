/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:23:15 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:07:36 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_fillarg(const char *format, va_list ap, int *i, t_arg *arg)
{
	ft_fillflags(format, i, arg);
	ft_fillfields(format, i, arg);
	if (!ft_fillconv(format, i, arg))
		return (-1);
	if (format[*i] == '%')
	{
		(*i)++;
		return (pct_arg(arg));
	}
	(*arg).type = format[*i];
	if (format[*i] != 0)
		(*i)++;
	return (ft_conv_distribution(arg, ap));
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	static t_arg	arg = {.type = -1};

	if (arg.type == -1)
		arg = ft_arginit();
	arg.len = 0;
	arg.last_arg = 0;
	va_start(ap, format);
	i = 0;
	while (format[i] != 0)
	{
		if (format[i] != 37)
			ft_putbuffer(&arg, format[i++]);
		else
		{
			i++;
			if (ft_fillarg(format, ap, &i, &arg) == -1)
				return (ft_error(&arg, ap));
			arg.last_arg = arg.index;
		}
	}
	va_end(ap);
	ft_printbuffer(&arg);
	return (arg.len);
}
