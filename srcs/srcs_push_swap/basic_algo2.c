/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_algo1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:00:43 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/17 22:59:09 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_putstackb(t_list *stack_a, t_list *stack_b, t_data *data)
{
	if (data->curr_one > data->best_one)
		return (ft_algofailed(stack_a, stack_b, data));
	if (stack_a == NULL)
		return (stack_b);
	if ()
	
}

t_list	*ft_stackbsort(t_list *stack_a, t_data *data)
{
	t_list *stack_b;

	if (VAL_A1 > VAL_A2)
		stack_a = ft_swap_a(stack_a, stack_a->next, data);
	stack_b = ft_push_a(&stack_a, NULL, data);
	ft_putstackb(stack_a, stack_b, data);

}
