/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:37:00 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/22 17:25:10 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_merge(t_list *left, t_list *right, t_data *data, t_list **lst)
{
	int		size_l;
	int		size_r;
	int		i;
	int		j;

	size_l = ft_lstsize(left);
	size_r = ft_lstsize(right);
	data->size++;
	data->size--;
	ft_putendl("Pile left");
	ft_printlist(left);
	ft_putendl("Pile right");
	ft_printlist(right);
	ft_putendl("Pile lst");
	ft_printlist(*lst);
	j = 0;
	i = 0;
	while (i < size_l && j < size_r)
	{
		if (*((int *)(left)->content) < *((int *)(right)->content))
		{
			ft_rotate_a(&left);
			i++;
		}
		else
		{
			left = ft_push_a(&right, left);
			ft_rotate_a(&left);
			j++;
		}
	}
	while (j < size_r)
	{
		left = ft_push_a(&right, left);
		ft_rotate_a(&left);
		j++;
	}
	ft_putendl("Pile left en fin de merge");
	ft_printlist(left);
	*lst = left;

}

static void	ft_mergesort(t_list **lst, t_data *data)
{
	int		n;
	t_list	*left;
	t_list	*right;
	t_list	*tmp;
	int		i;

	n = ft_lstsize(*lst);
	if (n < 2)
		return;
	i = 0;
	left = *lst;
	tmp = left;
	while (i < (n / 2) - 1)
	{
		tmp = tmp->next;
		i++;
	}
	right = tmp->next;
	tmp->next = NULL;
	ft_mergesort(&left, data);
	ft_mergesort(&right, data);
	ft_merge(left, right, data, lst);
}

t_list	*ft_launch_mergesort(t_list *a, t_data *data)
{
	data->curr_one = 0;
	ft_mergesort(&a, data);
	ft_putendl("Fin de tri fusion :");
	ft_printlist(a);
	return (a);
}
