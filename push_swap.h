/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:52:05 by kflorett          #+#    #+#             */
/*   Updated: 2022/02/02 16:14:29 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				a_score;
	int				b_score;
	int				way;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackadd_front(t_stack **stack, int value);
void	ft_stackadd_back(t_stack **stack, int value);
void	swap(t_stack *stack, int flag);
void	push(t_stack **src, t_stack **dst, int flag);
void	rotate(t_stack **src, int flag);
void	reverse_rotate(t_stack **src, int flag);
int		check_sort_rel(t_stack *stack);
int		check_sort_abs(t_stack *stack);
int		check_isvalid(int argc, char **argv, int flag);
void	quick_sort(t_stack **stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
void	long_sorting(t_stack **stack);
int		arr_score(t_stack *a, t_stack *b);
int		ar_score(t_stack *a, t_stack *b);
int		brr_score(t_stack *b);
int		br_score(t_stack *start, t_stack *b);
void	find_score(t_stack *a, t_stack *b);
int		best_score(t_stack *b);
void	way_one(t_stack **a, t_stack **b, int a_score, int b_score);
void	way_two(t_stack **a, t_stack **b, int a_score, int b_score);
void	way_three(t_stack **a, t_stack **b, int a_score, int b_score);
void	way_four(t_stack **a, t_stack **b, int a_score, int b_score);
void	sort(t_stack **a, t_stack **b);
int		check_intsize(int argc, char **argv, int flag);
int		check_noduplicate(int argc, char **argv, int flag);
void	short_sorting(t_stack **a);
void	reverse_rotate_twice(t_stack **a, t_stack **b, int flag);
void	rotate_twice(t_stack **a, t_stack **b, int flag);
void	swap_twice(t_stack *a, t_stack *b, int flag);
int		first_score(t_stack *b);
t_stack	*find_to_push(t_stack *b);
int		string_to_stack(t_stack **a, char **argv);
int		fill_stack(t_stack **a, int argc, char **argv);
void	free_stack(t_stack **a);
char	*ft_strexp(char *line, int c);
int		get_next_line(char **line, int fd);
int		check_line(t_stack **a, t_stack **b, char *line);
void	rotate_or_reverse(t_stack **a, t_stack **b, char *line);
void	swap_or_push(t_stack **a, t_stack **b, char *line);
int		check_command(t_stack **a, t_stack **b, char *line);
int		check_char(int argc, char **argv, int flag);
void	ft_error(char **str);
void	checker(t_stack **a);

#endif
