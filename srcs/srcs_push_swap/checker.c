/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:28:07 by ndelest           #+#    #+#             */
/*   Updated: 2018/03/03 15:54:24 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (VAL_A1 > VAL_A2)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int		ft_isnsort(t_list *stack_a)
{
	int		i;

	i = 1;
	while (stack_a->next != NULL)
	{
		if (VAL_A1 > VAL_A2)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
