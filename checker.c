/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:57:46 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:20:05 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strexp(char *line, int c)
{
	char	*str;
	int		i;

	i = ft_strlen(line);
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	get_next_line(char **line, int fd)
{
	int		i;
	char	buffer;
	int		flag;

	*line = malloc(1);
	if (!line)
		return (-1);
	*line[0] = '\0';
	i = 0;
	flag = read(fd, &buffer, 1);
	while (flag > 0)
	{
		if (buffer == '\n' && i != 0)
			break ;
		else if (buffer == '\n')
		{
			*line = ft_strexp(*line, buffer);
			break ;
		}
		*line = ft_strexp(*line, buffer);
		i++;
		flag = read(fd, &buffer, 1);
	}
	return (flag);
}

void	checker(t_stack **a)
{
	int		flag;
	t_stack	*b;
	char	*line;

	b = NULL;
	while (get_next_line(&line, 0))
	{
		flag = check_line(a, &b, line);
		if (flag != 0)
			break ;
		free(line);
	}
	free(line);
	if (flag == -2)
	{
		ft_putendl_fd("Error", 1);
		return ;
	}
	if (check_sort_abs(*a) == 0 && ft_stacksize(b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (ft_stacksize(b) != 0)
		free_stack(&b);
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
	checker(&a);
	free_stack(&a);
	return (0);
}
