/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:34:27 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:11:18 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_argreset(t_arg *arg)
{
	(*arg).type = 0;
	(*arg).minfield = 0;
	(*arg).precision = -1;
	ft_memset((*arg).flags, 0, 6);
	ft_memset((*arg).conv, 0, 5);
	(*arg).type_len = 0;
}

t_arg	ft_arginit(void)
{
	t_arg	arg;

	arg.type = 0;
	arg.minfield = 0;
	arg.precision = -1;
	ft_memset(arg.flags, 0, 6);
	ft_memset(arg.conv, 0, 5);
	arg.index = 0;
	arg.len = 0;
	arg.type_len = 0;
	return (arg);
}

void	ft_printbuffer(t_arg *arg)
{
	(*arg).buffer[(*arg).index] = 0;
	(*arg).len = (*arg).len + (*arg).index;
	write(1, (*arg).buffer, (*arg).index);
	(*arg).index = 0;
}

void	ft_putbuffer(t_arg *arg, unsigned char c)
{
	if ((*arg).index < BUFF_SIZE - 1)
		(*arg).buffer[(*arg).index++] = c;
	else
	{
		ft_printbuffer(arg);
		(*arg).buffer[(*arg).index++] = c;
	}
}
