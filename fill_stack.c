/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:05:26 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:22:08 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isvalid(int argc, char **argv, int flag)
{
	if (flag == 0 && argv[0] == NULL)
		return (-1);
	if (check_char(argc, argv, flag) == -1)
		return (-1);
	if (check_noduplicate(argc, argv, flag) == -1)
		return (-1);
	if (check_intsize(argc, argv, flag) == -1)
		return (-1);
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*ptr;

	while ((*a)-> next != NULL)
	{
		ptr = (*a)-> next;
		free(*a);
		*a = ptr;
	}
	free(*a);
}

void	ft_error(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	string_to_stack(t_stack **a, char **argv)
{
	int		i;
	int		temp;
	char	**stack;

	stack = ft_split(argv[1], ' ');
	i = 0;
	while (stack[i] != NULL)
		i++;
	if (check_isvalid(i, stack, 0) == -1)
	{
		ft_error(stack);
		return (-1);
	}
	i = 0;
	while (stack[i] != NULL)
	{
		temp = ft_atoi(stack[i]);
		free(stack[i]);
		ft_stackadd_back(a, temp);
		i++;
	}
	free(stack);
	return (0);
}

int	fill_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	int		temp;

	if (argc == 2)
	{
		if (string_to_stack(a, argv) == -1)
			return (-1);
	}
	else
	{
		if (check_isvalid(argc, argv, 1) == -1)
			return (-1);
		i = 1;
		while (i != argc)
		{
			temp = ft_atoi(argv[i]);
			ft_stackadd_back(a, temp);
			i++;
		}
	}
	return (0);
}
