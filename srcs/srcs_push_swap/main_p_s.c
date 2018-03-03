/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 20:42:15 by ndelest           #+#    #+#             */
/*   Updated: 2018/03/03 18:00:00 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_printlist(t_list *stack_a)
{
	ft_putstr("Etat de la pile : ");
	while (stack_a != NULL)
	{
		ft_printf("%d ", VAL_A1);
		stack_a = stack_a->next;
	}
	ft_putchar('\n');
}

t_list		*ft_lst_init(int ac, char *av[])
{
	t_list	*list;
	t_list	*tmp;
	int		j;
	int		i;

	i = 1;
	j = ft_atoi(av[i]);
	list = ft_lstnew((void *)&j, sizeof(int *));
	list->content_size = i++;
	while (i < ac)
	{
		j = ft_atoi(av[i]);
		tmp = ft_lstnew(&j, sizeof(int *));
		tmp->content_size = i++;
		ft_lstadd_last(&list, tmp);

	}
	return (list);
}

t_data	ft_data_init(void)
{
	t_data	data;

	data.size = 0;
	data.best_one = 0;
	data.curr_one = 0;
	return (data);
}

int		main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*tmp;
	t_data	data;

	if (ac > 1)
	{
		stack_a = ft_lst_init(ac, av);
		data = ft_data_init();
		data.size = ft_lstsize(stack_a);
		data.max = (int)(data).size;
		data.size_a = (int)(data).size;
		tmp = ft_lst_init(ac, av);
		if (!ft_sort_index(stack_a, &data))
			return (0);
	/*	ft_printlist(stack_a);
		stack_a = ft_swap_a(stack_a, stack_a->next);
		ft_printlist(stack_a);
		stack_a = ft_rotate_a(stack_a);
		ft_printlist(stack_a);
		stack_a = ft_revrotate_a(stack_a);
		ft_printlist(stack_a);
		ft_putstr("Push a :\n");
		ft_printlist(stack_a);
		ft_putstr("Push a 2 :\n");	
		ft_printlist(tmp);
		stack_a = tmp;
		ft_printlist(stack_a);
		stack_a = ft_basic1(stack_a, &data);
		ft_putendl("Resultat :");
		ft_printlist(stack_a);
		ft_printf("Nombre de coups : %zd\n", data.curr_one);*/
	//	stack_a = ft_revrotate_a(stack_a, &data);
		//stack_a = ft_mergesortreal_index(stack_a, &data);
	//	stack_a = ft_index_rotate_algo(stack_a, &data);
	//	stack_a = ft_launch_mergesort(stack_a, &data);
	/*	data.fin = 0;
		stack_a = ft_mergesort_launcher(stack_a, &data);
		ft_printf("Taille de la pile : %zd\n", data.size);
		ft_printf("Nombre de coups : %d\n", data.curr_one);
		if (data.curr_one < data.best_one || data.best_one == 0)
			data.best_one = data.curr_one;
		data.curr_one = 0;
		data.fin = 1;
		stack_a = tmp;
		stack_a = ft_mergesort_launcher(stack_a, &data);
		ft_printf("Taille de la pile : %zd\n", data.size);
		ft_printf("Nombre de coups : %d\n", data.curr_one);
		if (data.curr_one < data.best_one || data.best_one == 0)
			data.best_one = data.curr_one;
		data.fin = 2;
		data.curr_one = 0;
		tmp = ft_lst_init(ac, av);
		stack_a = tmp;
		stack_a = ft_mergesort_launcher(stack_a, &data);
		ft_printf("Taille de la pile : %zd\n", data.size);
		ft_printf("Nombre de coups : %d\n", data.curr_one);
		if (data.curr_one < data.best_one || data.best_one == 0)
			data.best_one = data.curr_one;
		data.fin = 3;
		data.curr_one = 0;
		tmp = ft_lst_init(ac, av);
		stack_a = tmp;
		stack_a = ft_mergesort_launcher(stack_a, &data);
		ft_printf("Nombre d'entiers : %zd\n", data.size);
		ft_printf("Nombre de coups : %d\n", data.curr_one);
		if (data.curr_one < data.best_one || data.best_one == 0)
			data.best_one = data.curr_one;*/
		data.fin = 2;
		data.curr_one = 0;
		tmp = ft_lst_init(ac, av);
		stack_a = tmp;
		stack_a = ft_mergesort_launcher(stack_a, &data);
		ft_printf("nombre d'entiers: %zd\n", data.size);
		ft_printf("Nombre de coups : %d\n", data.curr_one);
		if (data.curr_one < data.best_one || data.best_one == 0)
			data.best_one = data.curr_one;
		ft_printf("Meilleur nombre de coup : %d\n", data.best_one);
	}
	return (1);
}
