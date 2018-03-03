/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:59:06 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:26:00 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putfield(t_arg *arg, char c, int opt)
{
	int		i;
	int		j;
	int		isneg;

	i = 0;
	isneg = 0;
	if ((*arg).flags[1] == '-')
		isneg = 1;
	if (opt == 1)
	{
		if ((*arg).precision > (int)(*arg).type_len - isneg)
			j = (*arg).precision + isneg;
		else
			j = (int)(*arg).type_len;
		if (isneg == 0 && ((*arg).flags[1] == '+' || (*arg).flags[2] == ' '))
			++j;
		while (i++ < ((*arg).minfield - j))
			ft_putbuffer(arg, c);
	}
	if (opt == 2)
	{
		j = ((*arg).precision - (int)(*arg).type_len) + isneg;
		while (i++ < j)
			ft_putbuffer(arg, (unsigned char)c);
	}
}

static void	ft_puthashtag(t_arg *arg)
{
	ft_putbuffer(arg, '0');
	if ((*arg).type == 'x' || (*arg).type == 'X')
		ft_putbuffer(arg, (unsigned char)(*arg).type);
}

void		ft_putflagsnb(t_arg *arg)
{
	if ((*arg).minfield > 0 && (*arg).flags[4] != '-' && (((*arg).flags[3]
					== '0' && (*arg).precision >= 0) || (*arg).flags[3] != '0'))
		ft_putfield(arg, ' ', 1);
	if ((*arg).flags[0] != 0)
		ft_puthashtag(arg);
	if ((*arg).flags[1] != 0)
		ft_putbuffer(arg, (unsigned char)(*arg).flags[1]);
	else if ((*arg).flags[2] != 0)
		ft_putbuffer(arg, (unsigned char)' ');
	if ((*arg).precision >= 0)
		ft_putfield(arg, '0', 2);
	else if ((*arg).flags[3] == '0' && (*arg).flags[4] != '-')
		ft_putfield(arg, '0', 1);
}

void		ft_putflagstring(t_arg *arg)
{
	int		i;

	i = 0;
	if ((*arg).precision > 0 && (*arg).precision < (int)(*arg).type_len)
		(*arg).type_len = (*arg).precision;
	if ((*arg).flags[4] == '-')
		while (i < (int)(*arg).type_len)
			ft_putbuffer(arg, (unsigned char)(*arg).stock[i++]);
	i = 0;
	while (i++ < (*arg).minfield - (int)(*arg).type_len)
		ft_putbuffer(arg, (unsigned char)(*arg).flags[3]);
}

void		ft_putflagschar(t_arg *arg, size_t type_len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if ((*arg).flags[3] == '0' && (*arg).flags[4] != '-')
		c = '0';
	if ((*arg).flags[4] != '-')
		while (i++ < (*arg).minfield - (int)type_len)
			ft_putbuffer(arg, (unsigned char)c);
}
