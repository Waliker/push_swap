/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:15:44 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/17 19:59:34 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_index(int *tab, int i, int j)
{
	int				tmp1;

	tmp1 = tab[j];
	tab[j] = tab[i];
	tab[i] = tmp1;
}

static int	*ft_copylitotab(t_list *stack_a, t_data *data)
{
	int		*tab;
	int		i;

	if (!(tab = ft_memalloc(sizeof(int) * data->size)))
		return (NULL);
	if (!(data->index = ft_memalloc(sizeof(int) * data->size)))
		return (NULL);
	i = 0;
	while (stack_a != NULL)
	{
		tab[i] = VAL_A1;
		data->index[i] = (int)(stack_a)->content_size;
		i++;
		stack_a = stack_a->next;
	}
	return (tab);
}

int			ft_sort_index(t_list *stack_a, t_data *data)
{
	int		i;
	int		j;
	int		*tab_val;

	if (!(tab_val = ft_copylitotab(stack_a, data)))
			return (0);
	i = 0;
	while (i < (int)(data)->size)
	{
		j = i + 1;
		while (j < (int)(data)->size)
		{
			if (tab_val[i] <= tab_val[j])
				j++;
			else
			{
				ft_swap_index(tab_val, i, j);
				ft_swap_index(data->index, i, j);
				i--;
				j = (int)data->size;
			}
		}
		i++;
	}
	ft_memdel((void **)&tab_val);
	return (1);
}
