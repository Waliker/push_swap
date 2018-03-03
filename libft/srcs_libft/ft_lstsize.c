/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:15:15 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/15 16:34:57 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list *begin)
{
	size_t	size;

	size = 0;
	while (begin != NULL)
	{
		begin = begin->next;
		size++;
	}
	return (size);
}
