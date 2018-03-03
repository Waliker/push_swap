/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlowercase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:02:39 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/11 14:19:56 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}
