/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:56:18 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/18 18:18:29 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_shortway_value(t_list *a, t_list *b, int size_a)
{
	int		i;

	i = 0;
	while (i <= size_a / 2)
	{
		if (*((int *)(a)->content) > *((int *)(b)->content) && *((int *)(a)->content) < 
				*((int *)(b)->next->content))
			return (1);
		b = b->next;
		ft_printf("Valeur de b : %d\n", *((int *)(b)->content));
		ft_printf("Valeur de size_a : %d\n", size_a);
	ft_putendl("Je suis dans short");
		i++;
	}
	return (0);
}

int			ft_shortway_limits(t_list *b, int limits, int size_a)
{
	int		i;

	i = 0;
	while (i <= size_a / 2)
	{
		if (limits == *((int *)(b)->content))
			return (1);
		b = b->next;
		i++;
	}
	return (0);
}

int			ft_findtheslot(t_list **a, t_list **b, t_data *data, int count)
{
	ft_putendl("Je suis au debut de findslot");
	ft_printf("valeur de count : %d\n", count);
	if (*((int *)(*a)->content) < *((int *)(*b)->content) && *((int *)(*a)->content) > 
			*((int *)(*b)->next->content))
	{
		ft_rotate_a(b);
		*b = ft_push_a(a, *b);
		count = count + 2;
		return (count);
	}
	else if (ft_shortway_value(*a, *b, data->size_a))
		return (ft_findtheslot(a, ft_rotate_a(b), data, count + 1));
	else
		return (ft_findtheslot(a, ft_rotate_a(b), data, count + 1));
}

/*static int			ft_find_index(t_list *stack, int index)
{
	while (stack != NULL)
	{
		if (index == (int)(stack)->content_size)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int			ft_range_index(int index, int *tab)
{
	int		i;

	i = 0;
	while (index != tab[i])
		++i;
	return (i);
}*/

static int	ft_recur_sort(t_list **a, t_list **b, t_data *data, int count)
{
	ft_putendl("Je suis au debut");
	ft_printlist(*b);
	ft_printf("Valeur de size_a : %d\n", data->size_a);
	ft_printf("Valeur de count : %d\n", count);
	if (*a == NULL)
		return (count);
	else if (*((int *)(*a)->content) > data->val_min && *((int *)(*a)->content) < data->val_max)
	{
		ft_putendl("Je suis au debut inter");
		count = ft_findtheslot(a, b, data, count);
		data->size_a++;
		ft_putendl("Etat de b apres un inter :");
		ft_printlist(*b);
		return (ft_recur_sort(a, b, data, count));
	}
	else if (*((int *)(*a)->content) < data->val_min)
	{
		if (data->val_min == *((int *)(*b)->content))
		{
			*b = ft_push_a(a, *b);
			data->size_a++;
			data->val_min = *((int *)(*b)->content);
			ft_putendl("Etat de b apres un min :");
			ft_printlist(*b);
			return (ft_recur_sort(a, b, data, count + 1));
		}
		else
		{
		if (ft_shortway_limits(*b, data->val_min, data->size_a))
			return (ft_recur_sort(a, ft_rotate_a(b), data, count + 1));
		else
			return (ft_recur_sort(a, ft_revrotate_a(b), data, count + 1));

		}
	}
	else
	{
		if (data->val_max == *((int *)(*b)->content))
		{
			ft_rotate_a(b);
			*b = ft_push_a(a, *b);
			data->size_a++;
			data->val_max = *((int *)(*b)->content);
			ft_putendl("Etat de b apres un max :");
			ft_printlist(*b);
			return (ft_recur_sort(a, b, data, count + 2));
		}
		else
		{
			if (ft_shortway_limits(*b, data->val_max, data->size_a))
				return (ft_recur_sort(a, ft_rotate_a(b), data, count + 1));
			else
				return (ft_recur_sort(a, ft_revrotate_a(b), data, count + 1));
		}
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

t_list*		ft_mergesortreal_index(t_list *a, t_data *data)
{
	t_list *b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (*((int *)(a)->content) > *((int *)(a)->next->content))
	{
		a = ft_swap_a(a, a->next);
		data->curr_one = 1;
	}
	b = ft_push_a(&a, NULL);
	data->val_min = *((int *)(b)->content);
	b = ft_push_a(&a, b);
	data->val_max = *((int *)(b)->content);
	data->size_a = 2;
	data->curr_one = data->curr_one + 2;
	data->curr_one = data->curr_one + ft_recur_sort(&a, &b, data, count);
	ft_putendl("etat de b");
	ft_printf("Valeur de val_max : %d\n", data->val_max);
	ft_printf("Valeur de val_min : %d\n", data->val_min);
	while (*((int *)(b)->content) != data->val_max)
		ft_rotate_a(&b);
	ft_printf("Nom de coup jusaui ici : %d\n", data->curr_one);
	ft_printlist(b);
	i = data->size - 1;
	//	data->curr_one = data->curr_one + ft_recur_algo(&b, &a, data, i, count);
	ft_putendl("je sors");
	return (a);
}
