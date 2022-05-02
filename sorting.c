/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:34:41 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:17:43 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	way_one(t_stack **a, t_stack **b, int a_score, int b_score)
{
	if (a_score >= b_score)
	{
		a_score = a_score - b_score;
		while (b_score-- != 0)
			rotate_twice(a, b, 0);
		while (a_score-- != 0)
			rotate(a, 0);
	}
	else
	{
		b_score = b_score - a_score;
		while (a_score-- != 0)
			rotate_twice(a, b, 0);
		while (b_score-- != 0)
			rotate(b, 1);
	}
	push(b, a, 0);
}

void	way_two(t_stack **a, t_stack **b, int a_score, int b_score)
{
	while (a_score != 0)
	{
		rotate(a, 0);
		a_score--;
	}
	while (b_score != 0)
	{
		reverse_rotate(b, 1);
		b_score--;
	}
	push(b, a, 0);
}

void	way_three(t_stack **a, t_stack **b, int a_score, int b_score)
{
	while (a_score != 0)
	{
		reverse_rotate(a, 0);
		a_score--;
	}
	while (b_score != 0)
	{
		rotate(b, 1);
		b_score--;
	}
	push(b, a, 0);
}

void	way_four(t_stack **a, t_stack **b, int a_score, int b_score)
{
	if (a_score >= b_score)
	{
		a_score = a_score - b_score;
		while (b_score-- != 0)
			reverse_rotate_twice(a, b, 0);
		while (a_score-- != 0)
			reverse_rotate(a, 0);
	}
	else
	{
		b_score = b_score - a_score;
		while (a_score-- != 0)
			reverse_rotate_twice(a, b, 0);
		while (b_score-- != 0)
			reverse_rotate(b, 1);
	}
	push(b, a, 0);
}

void	sort(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*start_b;

	len = ft_stacksize(*b);
	while (len != 0)
	{
		find_score(*a, *b);
		start_b = find_to_push(*b);
		if (start_b -> way == 1)
			way_one(a, b, start_b -> a_score, start_b -> b_score);
		else if (start_b -> way == 2)
			way_two(a, b, start_b -> a_score, start_b -> b_score);
		else if (start_b -> way == 3)
			way_three(a, b, start_b -> a_score, start_b -> b_score);
		else if (start_b -> way == 4)
			way_four(a, b, start_b -> a_score, start_b -> b_score);
		len--;
	}
	quick_sort(a);
}
