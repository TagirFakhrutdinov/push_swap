/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:56:28 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:21:42 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_to_push(t_stack *b)
{
	int	i;
	int	score;

	score = best_score(b);
	while (b != NULL)
	{
		i = first_score(b);
		if (i == score)
			break ;
		b = b -> next;
	}
	return (b);
}

void	quick_sort(t_stack **stack)
{
	int		i;
	int		len;
	t_stack	*ptr;

	ptr = *stack;
	i = 1;
	while ((ptr -> value) < (ptr -> next -> value))
	{
		i++;
		ptr = ptr -> next;
	}
	len = ft_stacksize(*stack) - i;
	if (len < i)
	{
		while (len-- != 0)
			reverse_rotate(stack, 0);
	}
	else
	{
		while (i-- != 0)
			rotate(stack, 0);
	}
}

void	short_sorting(t_stack **a)
{
	swap(*a, 0);
	if (check_sort_abs(*a) != 0)
		quick_sort(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		return (-1);
	if (fill_stack(&a, argc, argv) == -1)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (check_sort_abs(a) == 0)
	{
		free_stack(&a);
		return (0);
	}
	if (check_sort_rel(a) == 0)
		quick_sort(&a);
	else
	{
		if (ft_stacksize(a) < 4)
			short_sorting(&a);
		else
			long_sorting(&a);
	}
	free_stack(&a);
	return (0);
}
