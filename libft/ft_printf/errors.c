/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 18:25:16 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 15:09:09 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_error(t_arg *arg, va_list ap)
{
	(*arg).index = (*arg).last_arg;
	va_end(ap);
	ft_printbuffer(arg);
	ft_argreset(arg);
	return (-1);
}
