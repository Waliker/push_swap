/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:56:18 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/18 01:13:26 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_index(t_list *stack, int index)
{
	while (stack != NULL)
	{
		if (index == (int)(stack)->content_size)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int			ft_range_index(int index, int *tab)
{
	int		i;

	i = 0;
	while (index != tab[i])
		++i;
	return (i);
}

static int	ft_recur_sort(t_list **a, t_list **b, t_data *data, int count)
{
	if (*a == NULL || ft_issort(*a))
		return (count);
	else if (ft_range_index((int)(*a)->content_size, data->index) >
			ft_range_index((int)(*b)->content_size, data->index) && 
			ft_range_index((int)(*a)->content_size, data->index) < 
			ft_range_index((int)(*b)->next->content_size, data->index))
	{
		ft_rotate_a(b);
		ft_putendl("Je passe dans celle ci");
		*b = ft_push_a(a, *b);
		return (ft_recur_sort(a, ft_rotate_a(b), data, count + 2));
	}
	else
	{
		ft_rotate_a(b);
		ft_putendl("Je passe dans la deuxieme");
		ft_printf("range index de a : %d\n", ft_range_index((int)(*a)->content_size, data->index));
		ft_printf("range index de b : %d\n", ft_range_index((int)(*b)->content_size, data->index));
		ft_printf("range index de next b : %d\n", ft_range_index((int)(*b)->next->content_size, data->index));
		ft_printlist(*b);
		return (ft_recur_sort(a, b, data, count + 1));
	}
}

/*static int	ft_recur_algo(t_list **a, t_list **b, t_data *data, int i, int count)
{
	if (*a == NULL)
		return (count);
	else if	(ft_find_index(*b, data->index[i]) == 1)
	{
		return (ft_recur_algo(a, b, data, i - 1, count));
	}
	else if ((int)(*a)->content_size == data->index[i])
	{
		*b = ft_push_a(a, *b);
		count = count + 1;
		data->size_a--;
		return (ft_recur_algo(a, b, data, i - 1, count));
	}
	else if ((int)(*a)->next->content_size == data->index[i])
	{
		count = count + 1;
		*a = ft_swap_a(*a, (*a)->next);
		return (ft_recur_algo(a, b, data, i, count));
	}
	else
	{
		count = count + 1;
		ft_putendl("Je rotate");
		if (ft_shortway(*a, data, data->index[i]))
			return(ft_recur_algo(ft_rotate_a(a), b, data, i, count));
		else
			return (ft_recur_algo(ft_revrotate_a(a), b, data, i, count));

	}
}*/

t_list*		ft_mergesort_index(t_list *a, t_data *data)
{
	t_list *b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	 if (ft_range_index((int)(a)->content_size, data->index) >
			ft_range_index((int)(a)->next->content_size, data->index))
	{
		a = ft_swap_a(a, a->next);
		data->curr_one = 1;
	}
	b = ft_push_a(&a, NULL);
	b = ft_push_a(&a, b);
	data->curr_one = data->curr_one + 2;
	data->curr_one = data->curr_one + ft_recur_sort(&a, &b, data, count);
	ft_putendl("etat de b");
	ft_printf("Nom de coup jusaui ici : %d\n", data->curr_one);
	ft_printlist(b);
	i = data->size - 1;
//	data->curr_one = data->curr_one + ft_recur_algo(&b, &a, data, i, count);
	ft_putendl("je sors");
	return (a);
}
