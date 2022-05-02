NAME	=	push_swap
NAME_B	=	checker

SRCS	=	push_swap.c\
			stackop_basic.c\
			swap_and_push.c\
			rotate.c\
			check_stack.c\
			presorting.c\
			find_score.c\
			sorting.c\
			fill_stack.c

SRCS_B	=	checker.c\
			checker_utils.c\
			check_stack.c\
			swap_and_push.c\
			rotate.c\
			fill_stack.c\
			stackop_basic.c\

HEADER	= 	push_swap.h

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

OBJS_B	=	$(patsubst %.c,%.o,$(SRCS_B))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
		@$(MAKE) -C libft
		@$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -o $(NAME)

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

bonus	:	$(NAME_B)

$(NAME_B)	:	$(OBJS_B) $(HEADER)
			@$(CC) $(OBJS_B) $(CFLAGS) ./libft/libft.a -o $(NAME_B)

clean	:
		$(MAKE) -C libft clean
		@rm -f $(OBJS)
		@rm -f $(OBJS_B)

fclean	:	clean
		$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@$(RM) $(NAME_B)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
