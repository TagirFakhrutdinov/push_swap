/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:47:15 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 15:50:47 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_rel(t_stack *stack)
{
	t_stack	*start;

	start = stack;
	while (stack -> next != NULL)
	{
		if ((stack -> value) > (stack -> next -> value))
		{
			stack = stack -> next;
			while (stack -> next != NULL)
			{
				if ((stack -> value) > (stack -> next -> value))
					return (-1);
				stack = stack -> next;
			}
			if ((stack -> value) > (start -> value))
				return (-1);
			break ;
		}
		stack = stack -> next;
	}
	return (0);
}

int	check_sort_abs(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if ((stack -> value) > (stack -> next -> value))
			return (-1);
		stack = stack -> next;
	}
	return (0);
}

int	check_intsize(int argc, char **argv, int flag)
{
	int				i;
	long long int	number;

	i = 1;
	if (flag == 0)
		i = 0;
	while (i != argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		number = ft_atoi(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	check_noduplicate(int argc, char **argv, int flag)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 0)
		i = 0;
	while (i != argc - 1)
	{
		j = i + 1;
		while (j != argc)
		{
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_char(int argc, char **argv, int flag)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 0)
		i = 0;
	while (i != argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (-1);
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]) != 0)
				j++;
			else if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}
