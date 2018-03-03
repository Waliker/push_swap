/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_decimaltype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:51:36 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:07:24 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_zmodifier(va_list ap, t_arg *arg)
{
	(*arg).typearg.sszi = va_arg(ap, ssize_t);
	(*arg).stock = ft_imtoa((*arg).typearg.sszi);
}

static void	ft_jmodifier(va_list ap, t_arg *arg)
{
	(*arg).typearg.im = va_arg(ap, intmax_t);
	(*arg).stock = ft_imtoa((*arg).typearg.im);
}

static void	ft_hmodifier(va_list ap, t_arg *arg)
{
	if ((*arg).conv[1] == 'h')
	{
		(*arg).typearg.c = (char)va_arg(ap, int);
		(*arg).stock = ft_imtoa((int)(*arg).typearg.c);
	}
	else
	{
		(*arg).typearg.shi = (short int)va_arg(ap, int);
		(*arg).stock = ft_imtoa((*arg).typearg.shi);
	}
}

static void	ft_lmodifier(va_list ap, t_arg *arg)
{
	if ((*arg).conv[1] == 'l')
	{
		(*arg).typearg.lli = va_arg(ap, long long int);
		(*arg).stock = ft_imtoa((*arg).typearg.lli);
	}
	else
	{
		(*arg).typearg.li = va_arg(ap, long int);
		(*arg).stock = ft_imtoa((*arg).typearg.li);
	}
}

int			ft_signedint(va_list ap, t_arg *arg)
{
	if ((*arg).conv[0] == 'l')
		ft_lmodifier(ap, arg);
	else if ((*arg).conv[0] == 0)
	{
		(*arg).typearg.i = va_arg(ap, int);
		(*arg).stock = ft_itoa((*arg).typearg.i);
	}
	else if ((*arg).conv[0] == 'h')
		ft_hmodifier(ap, arg);
	else if ((*arg).conv[0] == 'j')
		ft_jmodifier(ap, arg);
	else
		ft_zmodifier(ap, arg);
	if ((*arg).stock == NULL)
	{
		va_end(ap);
		exit(EXIT_FAILURE);
	}
	(*arg).type_len = ft_strlen((*arg).stock);
	if ((*arg).precision == 0 && (*arg).stock[0] == '0')
		(*arg).type_len = 0;
	return (1);
}
