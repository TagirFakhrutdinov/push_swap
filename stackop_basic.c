/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackop_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:15:06 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 15:02:42 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_stack **stack, int value)
{
	t_stack	*new;

	new = ft_stacknew(value);
	if (*stack == (void *)0)
		*stack = new;
	else
	{
		new -> next = *stack;
		*stack = new;
	}
}

void	ft_stackadd_back(t_stack **stack, int value)
{
	t_stack	*last;
	t_stack	*new;

	new = ft_stacknew(value);
	if (*stack == (void *)0)
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last -> next = new;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != (void *)0)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	int	len;

	len = ft_stacksize(stack);
	if (stack == (void *)0)
		return ((void *)0);
	while (len - 1 != 0)
	{
		stack = stack -> next;
		len--;
	}
	return (stack);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == (void *)0)
		return ((void *)0);
	node -> value = value;
	node -> a_score = 0;
	node -> b_score = 0;
	node -> way = 0;
	node -> next = (void *)0;
	return (node);
}
