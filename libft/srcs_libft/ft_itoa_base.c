/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:21:11 by ndelest           #+#    #+#             */
/*   Updated: 2018/01/23 15:44:09 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int n, int i, int base)
{
	if (n >= base || n <= -base)
		return (ft_power(n / base, i + 1, base));
	else
		return (i);
}

static void		ft_strnbr(char *str, int n, int base, int i)
{
	i--;
	if (n < 0)
	{
		while (n <= -base)
		{
			str[i--] = -(n % base) + (n % base > 9 ? 'A' - 10 : 48);
			n = n / base;
		}
		str[i--] = -n + (n % base > 9 ? 'A' - 10 : 48);
		str[i] = '-';
	}
	else
	{
		while (n >= base)
		{
			str[i--] = (n % base) + (n % base > 9 ? 'A' - 10 : 48);
			n = n / base;
		}
		str[i] = n + (n % base > 9 ? 'A' - 10 : 48);
	}
}

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	int		size;
	int		isneg;
	int		i;

	if (n < 0)
		isneg = 1;
	else
		isneg = 0;
	i = 1;
	size = ft_power(n, i, base);
	i = size + isneg;
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_strnbr(str, n, base, i);
	return (str);
}
