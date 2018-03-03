/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_algo1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:56:40 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/18 18:29:05 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_split_a(t_list **stack_a, t_data *data)
{
	t_list	*stack_b;
	size_t	i;

	stack_b = NULL;
	i = 0;
	while (i < data->size / 2)
	{
		stack_b = ft_push_a(stack_a, stack_b);
		i++;
		data->curr_one++;
	}
	return (stack_b);
}

t_list	*ft_sortnmerge(t_list *stack_a, t_list *stack_b, t_data *data)
{
	if (stack_b == NULL)
		return (stack_a);
	if (stack_b->next != NULL && VAL_B1 < VAL_B2)
		return (ft_sortnmerge(stack_a, ft_swap_a(stack_b, stack_b->next), data));
	else if (stack_a->next != NULL && VAL_A1 > VAL_A2)
		return (ft_sortnmerge(ft_swap_a(stack_a, stack_a->next), stack_b, data));
	else
		return (ft_sortnmerge(ft_push_a(&stack_b, stack_a), stack_b, data));
}

t_list	*ft_basic1(t_list *stack_a, t_data *data)
{	
	t_list	*stack_b;
	
	if (data->curr_one > data->best_one && data->best_one != 0)
	{
		data->curr_one = 0;
		return (stack_a);
	}
	if (!ft_issort(stack_a))
	{
		if (VAL_A1 > VAL_A2)
			stack_a = ft_swap_a(stack_a, stack_a->next);
		stack_b = ft_split_a(&stack_a, data);
		stack_a = ft_sortnmerge(stack_a, stack_b, data);
		ft_printlist(stack_a);
		return (ft_basic1(stack_a, data));
	}
	else
		return (stack_a);
}
