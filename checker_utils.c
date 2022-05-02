/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:38:28 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:57:06 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa", 3)
		|| !ft_strncmp(line, "sb", 3) || !ft_strncmp(line, "ss", 3))
	{
		swap_or_push(a, b, line);
		return (0);
	}
	if (!ft_strncmp(line, "pa", 3) || !ft_strncmp(line, "pb", 3))
	{
		swap_or_push(a, b, line);
		return (0);
	}
	if (!ft_strncmp(line, "ra", 3)
		|| !ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3))
	{
		rotate_or_reverse(a, b, line);
		return (0);
	}
	if (!ft_strncmp(line, "rra", 4)
		|| !ft_strncmp(line, "rrb", 4) || !ft_strncmp(line, "rrr", 4))
	{
		rotate_or_reverse(a, b, line);
		return (0);
	}
	return (-1);
}

int	check_line(t_stack **a, t_stack **b, char *line)
{
	if (check_command(a, b, line) == 0)
		return (0);
	if (!ft_strncmp(line, "\n", 1))
		return (-1);
	return (-2);
}

void	rotate_or_reverse(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra", 2) == 0)
		rotate(a, 2);
	if (ft_strncmp(line, "rb", 2) == 0)
		rotate(b, 2);
	if (ft_strncmp(line, "rr", 3) == 0)
		rotate_twice(a, b, 1);
	if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate(a, 2);
	if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate(b, 2);
	if (ft_strncmp(line, "rrr", 3) == 0)
		reverse_rotate_twice(a, b, 1);
}

void	swap_or_push(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap(*a, 2);
	if (ft_strncmp(line, "sb", 2) == 0)
		swap(*b, 2);
	if (ft_strncmp(line, "ss", 2) == 0)
		swap_twice(*a, *b, 1);
	if (ft_strncmp(line, "pa", 2) == 0)
		push(b, a, 2);
	if (ft_strncmp(line, "pb", 2) == 0)
		push(a, b, 2);
}
