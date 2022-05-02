/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:34:12 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 15:19:05 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_score(t_stack *a, t_stack *b)
{
	int		len;
	int		i;
	t_stack	*prev;

	i = 0;
	prev = ft_stacklast(a);
	len = ft_stacksize(a);
	while (a != NULL)
	{
		if ((b -> value < a -> value) && (prev -> value < b -> value))
			break ;
		prev = a;
		a = a -> next;
		i++;
	}
	len = len - i;
	return (len);
}

int	ar_score(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*prev;

	i = 0;
	prev = ft_stacklast(a);
	while (a != NULL)
	{
		if ((b -> value < a -> value) && (prev -> value < b -> value))
			break ;
		prev = a;
		a = a -> next;
		i++;
	}
	return (i);
}

int	brr_score(t_stack *b)
{
	int	i;

	i = 0;
	while (b != NULL)
	{
		b = b -> next;
		i++;
	}
	return (i);
}

int	br_score(t_stack *start, t_stack *b)
{
	int	i;

	i = 0;
	while (start -> value != b -> value)
	{
		start = start -> next;
		i++;
	}
	return (i);
}

void	find_score(t_stack *a, t_stack *b)
{
	t_stack	*start_b;

	start_b = b;
	while (b != NULL)
	{
		b -> way = 0;
		if (br_score(start_b, b) <= brr_score(b))
			b -> b_score = br_score(start_b, b);
		else
		{
			b -> b_score = brr_score(b);
			b -> way = 1;
		}
		if (ar_score(a, b) <= arr_score(a, b))
		{
			b -> a_score = ar_score(a, b);
			b -> way = b -> way + 1;
		}
		else
		{
			b -> a_score = arr_score(a, b);
			b -> way = b -> way + 3;
		}
		b = b -> next;
	}
}
