/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:30:00 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:17:33 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack -> value;
	stack = stack -> next;
	while (stack -> next != NULL)
	{
		if ((stack -> value) < min)
			min = stack -> value;
		stack = stack -> next;
	}
	if ((stack -> value) < min)
		min = stack -> value;
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack -> value;
	stack = stack -> next;
	while (stack -> next != NULL)
	{
		if ((stack -> value) > max)
			max = stack -> value;
		stack = stack -> next;
	}
	if ((stack -> value) > max)
		max = stack -> value;
	return (max);
}

int	first_score(t_stack *b)
{
	int	i;

	if (b -> way == 1 || b -> way == 4)
	{
		if (b -> a_score >= b -> b_score)
			i = b -> a_score;
		else
			i = b -> b_score;
	}
	else
		i = b -> a_score + b -> b_score;
	return (i);
}

int	best_score(t_stack *b)
{
	int	i;
	int	j;

	i = first_score(b);
	while (b != NULL)
	{
		j = first_score(b);
		if (i > j)
			i = j;
		b = b -> next;
	}
	return (i);
}

void	long_sorting(t_stack **a)
{
	int		min;
	int		max;
	int		len;
	t_stack	*b;

	min = find_min(*a);
	max = find_max(*a);
	len = ft_stacksize(*a) - 3;
	b = NULL;
	while (len != 0)
	{
		if (((*a)-> value != min) && ((*a)-> value != max))
		{
			push(a, &b, 1);
			len--;
		}
		else
			rotate(a, 0);
	}
	if (check_sort_rel(*a) == -1)
		swap(*a, 0);
	sort(a, &b);
}
