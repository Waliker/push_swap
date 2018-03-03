/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:28:51 by ndelest           #+#    #+#             */
/*   Updated: 2018/03/01 14:40:39 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push_a(t_list **stack_a, t_list *stack_b)
{
	t_list	*tmp;
//	ft_putendl("push");
	if (stack_b != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = stack_b;
		return (tmp);
	}
	else
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
	}
	return (tmp);
}

t_list	**ft_revrotate_a(t_list **begin)
{
	t_list	*tmp;

	if ((*begin)->next != NULL)
	{
//		ft_putendl("rra");
		tmp = *begin;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_first(begin, tmp->next);
		tmp->next = NULL;
	}
	return (begin);
}

t_list	**ft_rotate_a(t_list **begin)
{
	t_list	*tmp;

	tmp = *begin;
	if (tmp->next != NULL)
	{
//		ft_putendl("ra");
		*begin = (*begin)->next;
		tmp->next = NULL;
		ft_lstadd_last(begin, tmp);
	}
	return (begin);
}

t_list	*ft_rotate_fake_a(t_list *begin)
{
	t_list	*tmp;

	tmp = begin;
	if (tmp->next != NULL)
	{
//		ft_putendl("ra");
		begin = begin->next;
		tmp->next = NULL;
		ft_lstadd_last(&begin, tmp);
	}
	return (begin);
}


t_list	*ft_swap_a(t_list *current, t_list *next)
{
	current->next = next->next;
	ft_lstadd_first(&current, next);
	return (current);
}
