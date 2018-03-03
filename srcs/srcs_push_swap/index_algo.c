/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:23:01 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/22 15:25:10 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_shortway(t_list *stack, t_data *data)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	j = data->size_a / 2;
	while (i++ < data->size_a)
		tmp = tmp->next;
	i = 0;
	while (i <= data->size_a / 2)
	{
		stack = stack->next;
		i++;
		ft_printf("Valeur de dernier index : %d\n", data->index[data->fin]);
		ft_printf("Valeur de premier index : %d\n", data->index[data->deb]);
		if ((int)(stack)->content_size == data->index[data->deb] ||
				(int)(stack)->content_size == data->index[data->fin])
		{
			ft_putendl("je sors");
			break;
		}
	}
	if (i > data->size_a / 2)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		j--;
		ft_printf("Valeur de dernier index : %d\n", data->index[data->fin]);
		ft_printf("Valeur de premier index : %d\n", data->index[data->deb]);
		if ((int)(tmp)->content_size == data->index[data->deb] ||
				(int)(tmp)->content_size == data->index[data->fin])
		{
			ft_putendl("je sors");
			break;
		}
	}
	if (i > j)
		return (0);
	return (1);
}
/*static t_list	*ft_sortnmerge(t_list *stack_a, t_list *stack_b, t_data *data)
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
*/
t_list		*ft_lstcpy(t_list *list)
{
	t_list	*tmp;
	t_list	*begin;

	if (!(begin = ft_lstnew(list->content, sizeof(int *))))
		return (NULL);
	begin->content_size = list->content_size;
	list = list->next;
	while (list != NULL)
	{
		if (!(tmp = ft_lstnew(list->content, sizeof(int *))))
			return (NULL);
		tmp->content_size = list->content_size;
		ft_lstadd_last(&begin, tmp);
		list = list->next;
	}
	return (begin);
}

static int	ft_recur_algo(t_list **a, t_list **b, t_data *data, int count)
{
	if (data->size_a == 0)
		return (data->curr_one);
	else if ((int)(*a)->content_size == data->index[data->deb] || 
			(int)(*a)->content_size == data->index[data->fin])
	{
		ft_putendl("Je push");
		*b = ft_push_a(a, *b);
		count = count + 1;
		data->curr_one = data->curr_one + 1;
		data->size_a--;
		if ((int)(*b)->content_size == data->index[data->deb])
			data->deb++;	
		else
		{
			ft_rotate_a(b);
			count++;
			data->curr_one++;
			data->fin--;
		}
		return (ft_recur_algo(a, b, data, count));
	}
	else
	{
		count = count + 1;
		data->curr_one++;
		ft_putendl("Je rotate");
		if (ft_shortway(*a, data))
			return (ft_recur_algo(ft_rotate_a(a), b, data, count));
		else
			return (ft_recur_algo(ft_revrotate_a(a), b, data, count));
	}
}

t_list	*ft_index_rotate_algo(t_list *stack_a, t_data *data)
{
	t_list	*stack_b;

	ft_putendl("Etat de a :");
	ft_printlist(stack_a);
	stack_b = NULL;
	ft_printf("Valeur de max : %d\n", data->max);
	data->deb = 0;
	data->fin = data->size - 1;
	/*while (i < (int)(data)->size)
	  {
	  ft_printf("Valeur d'index rang %d : %d\n", i, data->index[i]);
	  i++;
	  }
	  tmp = stack_a;
	  while (tmp != NULL)
	  {
	  ft_printf("valeur de content size : %zd\n", tmp->content_size);
	  tmp = tmp->next;	
	  }*/
	data->curr_one = 0;
	data->curr_one = ft_recur_algo(&stack_a, &stack_b, data, 0);
	ft_printf("Valeur de curr_one :%d\n", data->curr_one);
	ft_printlist(stack_b);
/*	while (i < (int)(data)->size / 2)
	{
		tmp = ft_push_a(&stack_b, tmp);
		data->curr_one++;
		i++;
	}*/
	ft_putendl("coucou");
	return (stack_a);

}
