/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:09:50 by ndelest           #+#    #+#             */
/*   Updated: 2018/03/03 16:11:27 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/ft_printf/libftprintf.h"
# define VAL_A1 *((int *)(stack_a)->content)
# define VAL_A2 *((int *)(stack_a)->next->content)
# define VAL_B1 *((int *)(stack_b)->content)
# define VAL_B2 *((int *)(stack_b)->next->content)

typedef struct		s_data
{
	size_t			size;
	int				best_one;
	int				curr_one;
	int				*index;
	int				size_a;
	int				max;
	int				val_max;
	int				val_min;
	int				deb;
	int				fin;
}					t_data;
t_list	*ft_swap_a(t_list *current, t_list *next);
t_list	**ft_rotate_a(t_list **begin);
t_list	*ft_rotate_fake_a(t_list *begin);
t_list	**ft_revrotate_a(t_list **begin);
t_list	*ft_push_a(t_list **stack_a, t_list *stack_b);
int		ft_issort(t_list *stack_a);
int		ft_isnsort(t_list *stack_a);
t_list	*ft_basic1(t_list *stack_a, t_data *data);
void	ft_printlist(t_list *stack_a);
int		ft_sort_index(t_list *stack_a, t_data *data);
t_list	*ft_index_rotate_algo(t_list *stack_a, t_data *data);
t_list	*ft_mergesort_index(t_list *a, t_data *data);
int		ft_shortway(t_list *stack, t_data *data);
t_list	*ft_mergesortreal_index(t_list *a, t_data *data);
t_list	*ft_launch_mergesort(t_list *a, t_data *data);
t_list	*ft_mergesort_launcher(t_list *a, t_data *data);
#endif
