/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:40:49 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:16:02 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fillflags(const char *format, int *i, t_arg *arg)
{
	while (format[*i] == '#' || format[*i] == '+' || format[*i] == '-' ||
			format[*i] == '0' || format[*i] == ' ')
	{
		if (format[*i] == '#')
			(*arg).flags[0] = format[*i];
		else if (format[*i] == '+')
			(*arg).flags[1] = format[*i];
		else if (format[*i] == ' ')
			(*arg).flags[2] = format[*i];
		else if (format[*i] == '0')
			(*arg).flags[3] = format[*i];
		else if (format[*i] == '-')
			(*arg).flags[4] = format[*i];
		++(*i);
	}
}

void	ft_fillfields(const char *format, int *i, t_arg *arg)
{
	if (format[*i] >= 49 && format[*i] <= 57)
	{
		(*arg).minfield = format[(*i)++] - 48;
		while (format[*i] >= 48 && format[*i] <= 57)
			(*arg).minfield = ((*arg).minfield * 10) + format[(*i)++] - 48;
	}
	if (format[*i] == 46)
	{
		(*arg).precision = 0;
		++(*i);
		while (format[*i] >= 48 && format[*i] <= 57)
			(*arg).precision = ((*arg).precision * 10) + format[(*i)++] - 48;
	}
}

int		ft_fillconv(const char *format, int *i, t_arg *arg)
{
	int		j;

	j = 0;
	while (j < 3 && (format[*i] == 'h' || format[*i] == 'l' ||
				format[*i] == 'j' || format[*i] == 'z'))
		(*arg).conv[j++] = format[(*i)++];
	if (j > 2)
		return (0);
	if (((*arg).conv[0] == 'j' || (*arg).conv[0] == 'z')
			&& ((*arg).conv[1] != 0))
		return (0);
	if ((*arg).conv[0] != 0 && (*arg).conv[1] != 0 && (*arg).conv[0]
			!= (*arg).conv[1])
		return (0);
	return (1);
}
