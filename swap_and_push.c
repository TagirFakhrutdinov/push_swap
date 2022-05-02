/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:32:38 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 15:23:29 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_twice(t_stack *a, t_stack *b, int flag)
{
	swap(a, 2);
	swap(b, 2);
	if (flag == 0)
		ft_putendl_fd("ss", 1);
}

void	swap(t_stack *stack, int flag)
{
	int	temp;

	if (stack == NULL || stack -> next == NULL)
		return ;
	temp = stack -> value;
	stack -> value = stack -> next -> value;
	stack -> next -> value = temp;
	if (flag == 0)
		ft_putendl_fd("sa", 1);
	else if (flag == 1)
		ft_putendl_fd("sb", 1);
}

void	push(t_stack **src, t_stack **dst, int flag)
{
	t_stack	*save;

	if ((*src) == NULL)
		return ;
	save = (*src)-> next;
	if ((*dst) == NULL)
		(*dst) = ft_stacknew((*src)-> value);
	else
		ft_stackadd_front(dst, (*src)-> value);
	(*src)-> next = NULL;
	free(*src);
	*src = save;
	if (flag == 0)
		ft_putendl_fd("pa", 1);
	else if (flag == 1)
		ft_putendl_fd("pb", 1);
}
