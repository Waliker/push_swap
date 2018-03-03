/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_decimaltype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:51:36 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:06:59 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_zmodifier(va_list ap, t_arg *arg, int base)
{
	(*arg).typearg.szi = va_arg(ap, size_t);
	(*arg).stock = ft_uitoa_base((*arg).typearg.szi, base);
}

static void	ft_jmodifier(va_list ap, t_arg *arg, int base)
{
	(*arg).typearg.uim = va_arg(ap, uintmax_t);
	(*arg).stock = ft_uitoa_base((*arg).typearg.uim, base);
}

static void	ft_hmodifier(va_list ap, t_arg *arg, int base)
{
	if ((*arg).conv[1] == 'h')
	{
		(*arg).typearg.uc = (unsigned char)va_arg(ap, int);
		(*arg).stock = ft_uitoa_base((unsigned int)(*arg).typearg.uc, base);
	}
	else
	{
		(*arg).typearg.ushi = (unsigned short int)va_arg(ap, unsigned int);
		(*arg).stock = ft_uitoa_base((*arg).typearg.ushi, base);
	}
}

static void	ft_lmodifier(va_list ap, t_arg *arg, int base)
{
	if ((*arg).conv[1] == 'l')
	{
		(*arg).typearg.ulli = va_arg(ap, unsigned long long int);
		(*arg).stock = ft_uitoa_base((*arg).typearg.ulli, base);
	}
	else
	{
		(*arg).typearg.uli = va_arg(ap, unsigned long int);
		(*arg).stock = ft_uitoa_base((*arg).typearg.uli, base);
	}
}

int			ft_unsignedint(va_list ap, t_arg *arg, int base)
{
	if ((*arg).conv[0] == 'l')
		ft_lmodifier(ap, arg, base);
	else if ((*arg).conv[0] == 0)
	{
		(*arg).typearg.ui = va_arg(ap, unsigned int);
		(*arg).stock = ft_uitoa_base((*arg).typearg.ui, base);
	}
	else if ((*arg).conv[0] == 'h')
		ft_hmodifier(ap, arg, base);
	else if ((*arg).conv[0] == 'j')
		ft_jmodifier(ap, arg, base);
	else
		ft_zmodifier(ap, arg, base);
	if ((*arg).stock == NULL)
	{
		va_end(ap);
		exit(EXIT_FAILURE);
	}
	(*arg).type_len = ft_strlen((*arg).stock);
	if ((*arg).precision == 0 && (*arg).stock[0] == '0')
		(*arg).type_len = 0;
	else if ((*arg).stock[0] == '0')
		(*arg).flags[0] = 0;
	return (1);
}
