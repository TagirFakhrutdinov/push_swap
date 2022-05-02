/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:14:41 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 15:22:15 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_twice(t_stack **a, t_stack **b, int flag)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
	if (flag == 0)
		ft_putendl_fd("rrr", 1);
}

void	reverse_rotate(t_stack **src, int flag)
{
	t_stack	*new_first;
	t_stack	*new_last;
	t_stack	*old_first;

	if ((*src) == NULL || (*src)-> next == NULL)
		return ;
	old_first = *src;
	new_last = *src;
	while (new_last -> next -> next != NULL)
		new_last = new_last -> next;
	new_first = new_last -> next;
	new_first -> next = old_first;
	new_last -> next = NULL;
	*src = new_first;
	if (flag == 0)
		ft_putendl_fd("rra", 1);
	else if (flag == 1)
		ft_putendl_fd("rrb", 1);
}

void	rotate_twice(t_stack **a, t_stack **b, int flag)
{
	rotate(a, 2);
	rotate(b, 2);
	if (flag == 0)
		ft_putendl_fd("rr", 1);
}

void	rotate(t_stack **src, int flag)
{
	t_stack	*new_first;
	t_stack	*new_last;
	t_stack	*old_last;

	if ((*src) == NULL || (*src)-> next == NULL)
		return ;
	new_last = *src;
	new_first = (*src)-> next;
	old_last = *src;
	while (old_last -> next != NULL)
		old_last = old_last -> next;
	new_last -> next = NULL;
	old_last -> next = new_last;
	*src = new_first;
	if (flag == 0)
		ft_putendl_fd("ra", 1);
	else if (flag == 1)
		ft_putendl_fd("rb", 1);
}
