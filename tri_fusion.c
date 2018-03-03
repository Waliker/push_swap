/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:25:49 by ndelest           #+#    #+#             */
/*   Updated: 2018/03/03 15:47:22 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void		ft_visualize_sort(t_list *a, t_list *b)
{
	int		i;
	int		j;

	i = ft_lstsize(a);
	j = ft_lstsize(b);
	while (a != NULL || b != NULL)
	{
		if (i < j)
		{
			ft_printf("         %4d\n", *((int *)(b)->content));
			j--;
			b = b->next;
		}
		else if (i > j)
		{
			ft_printf("%4d\n", *((int *)(a)->content));
			i--;
			a = a->next;
		}
		else
		{
			ft_printf("%4d     %4d\n", *((int *)(a)->content), *((int *)(b)->content));
			i--;
			j--;
			a = a->next;
			b = b->next;
		}
	}
	ft_printf("-----     -----\n  a         b\n");
}


static void		ft_splitforsort_1(t_list **a, t_list **b, t_data *data, int i)
{
	while (i < (int)data->size / 2)
	{
		*b = ft_push_a(a, *b);
		i++;
		data->curr_one++;
	}
}

static void		ft_splitforsort_2(t_list **a, t_list **b, t_data *data, int i)
{
	while (i < (int)data->size / 2)
	{
		*b = ft_push_a(a, *b);
		i++;
		ft_rotate_a(a);
		data->curr_one = data->curr_one + 2;
	}
}

static void		ft_splitforsort_3(t_list **a, t_list **b, t_data *data, int i)
{
	while (i < (int)data->size / 2)
	{
		i++;
		ft_rotate_a(a);
		data->curr_one++;
	}
	while (i < (int)data->size)
	{
		*b = ft_push_a(a, *b);
		data->curr_one++;
		i++;
	}
}


   static void		ft_splitforsort(t_list **a, t_list **b, t_data *data, int i)
   {
   if (i < (int)data->size / 2)
   {
 *b = ft_push_a(a, *b);
 *b = ft_push_a(a, *b);
 data->curr_one = data->curr_one + 2;
 if (*((int *)(*a)->content) > *((int *)(*a)->next->content) ||
 *((int *)(*b)->content) > *((int *)(*b)->next->content))
 {
 if (*((int *)(*a)->content) > *((int *)(*a)->next->content) &&
 *((int *)(*b)->content) > *((int *)(*b)->next->content))
 {
 *a = ft_swap_a(*a, (*a)->next);
 *b = ft_swap_a(*b, (*b)->next);
 data->curr_one++;
 }
 else if (*((int *)(*a)->content) > *((int *)(*a)->next->content))
 {
 *a = ft_swap_a(*a, (*a)->next);
 data->curr_one++;
 }
 else
 {
 *b = ft_swap_a(*b, (*b)->next);
 data->curr_one++;
 }
 }
// ft_putendl("Dans le split");
 ft_rotate_a(a);
 ft_rotate_a(a);
 ft_rotate_a(b);
 ft_rotate_a(b);
 data->curr_one = data->curr_one + 2;
 return (ft_splitforsort(a, b, data, i + 2));
 }
 }

static void		ft_merge_in_one(t_list **a, t_list **b, t_data *data, int *i)
{
	int		l;
	int		r;
	int		len_a;
	int		len_b;

	l = 0;
	r = 0;
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	if (*i == 0 && len_a != len_b)
	{
		if (len_a >= data->max / 2)
			l = ft_isnsort(*a, data->max / 2);
		else
			l = (data->max / 2) - len_a;

		if (len_b >= data->max / 2)
			r = ft_isnsort(*b, data->max / 2);
		else
			r = (data->max / 2) - len_b;
	}
	ft_printf("valeur de l : %d\n", l);
	ft_printf("valeur de r : %d\n", r);
	/*	ft_putendl("Etat des piles en debut de fusion");
		ft_printlist(*a);
		ft_printlist(*b);
		ft_printf("valeur de i : %d\n", *i);
		ft_printf("taille de a : %d\n", ft_lstsize(*a));
		ft_printf("taille de b : %d\n", ft_lstsize(*b));
		ft_printf("Valeur de data max : %d\n", data->max);
		*/	while (l < data->max / 2 && r < data->max / 2 && *a != NULL && *b != NULL)
	{
		if (*((int *)(*a)->content) > *((int *)(*b)->content))
		{
			*a = ft_push_a(b, *a);
			ft_rotate_a(a);
			r++;
			data->curr_one = data->curr_one + 2;
		}
		else
		{
			ft_rotate_a(a);
			data->curr_one++;
			l++;
		}
	}
		ft_printf("valeur de r : %d et de l : %d\n", r, l);
	while (l < data->max / 2 && *a != NULL)
	{
		ft_rotate_a(a);
		data->curr_one++;
		ft_putendl("je fais tourner left");
		l++;
	}
	while (r < data->max / 2 && *b != NULL)
	{
		*a = ft_push_a(b, *a);
		ft_rotate_a(a);
		ft_putendl("je mets right dans left");
		r++;
		data->curr_one = data->curr_one + 2;
	}
	*i = *i + data->max;
	data->deb = -data->deb;
	/*	ft_printf("Data max a : %d et etat des piles a et b :\n", data->max);
		ft_printlist(*a);
		ft_printlist(*b);
		ft_printf("nombre de coup : %d\n", data->curr_one);
		ft_putendl("coucou");
		*/}

static void		ft_final_merge(t_list **a, t_list **b, t_data *data)
{
	int		i;
	int		j;

	i = ft_lstsize(*a);
	j = ft_lstsize(*b);
	while (j != 0 && i != 0)
	{
//		ft_putchar('a');
		if (*((int *)(*b)->content) < *((int *)(*a)->content))
		{
			*a = ft_push_a(b, *a);
			ft_rotate_a(a);
			data->curr_one = data->curr_one + 2;
			j--;
		}
		else
		{
			ft_rotate_a(a);
			i--;
			data->curr_one++;
		}
	}
//	ft_putendl("OU CA FOIRE BORDEL");
//	ft_visualize_sort(*a, *b);
	while (j != 0)
	{
//		ft_putchar('b');
		*a = ft_push_a(b, *a);
		ft_rotate_a(a);
		data->curr_one = data->curr_one + 2;
		j--;
	}
//	ft_putchar('C');
}

static void		ft_merge_sort(t_list **a, t_list **b, t_data *data, int i)
{
	if (ft_issort(*a) && ft_issort(*b))
		return (ft_final_merge(a, b, data));
	else if (data->max >= (int)data->size)
		return;
	else if (i + (data->max / 2) > (int)data->size - data->val_min)
	{
		data->max = data->max * 2;
		return (ft_merge_sort(a, b, data, 0));
	}
	else
	{
		ft_printf("Valeur de i : %d\n", i);
		ft_putendl("Etat des piles");
		ft_printf("Nombre d'entiers a deplacer : %d\n", data->max / 2);
		ft_visualize_sort(*a, *b);
		if (data->deb == 1)
		{
			ft_putendl("Left = b !");
			ft_merge_in_one(b, a, data, &i);
		}
		else
		{
			ft_putendl("Left = a !");
			ft_merge_in_one(a, b, data, &i);
		}
		return (ft_merge_sort(a, b, data, i));
	}
}

t_list	*ft_mergesort_launcher(t_list *a, t_data *data)
{
	t_list *b;

	b = NULL;
	data->max = 2;
	if (data->fin == 0)
		ft_splitforsort(&a, &b, data, 0);
	else if (data->fin == 1)
		ft_splitforsort_1(&a, &b, data, 0);
	else if (data->fin == 2)
		ft_splitforsort_2(&a, &b, data, 0);
	else if (data->fin == 3)
		ft_splitforsort_3(&a, &b, data, 0);
	else
	{
		ft_rotate_a(&a);
		data->curr_one++;
		ft_splitforsort(&a, &b, data, 0);
	}
	if (data->fin == 0 || data->fin == 4)
		data->max = 4;
	data->deb = 1;
	if (data->size % 2 != 0)
		data->val_min = 1;
	ft_putendl("DEBUT DE TRI FUSION :");
	ft_visualize_sort(a, b);
	ft_merge_sort(&a, &b, data, 0);
	ft_putendl("FIN DE TRI FUSION :");
	//ft_printlist(a);
	ft_visualize_sort(a, b);
	ft_printf("Taille de la liste a : %d\n", ft_lstsize(a));
	return (a);
}
