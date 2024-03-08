# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:08:32 by mualkhid          #+#    #+#              #
#    Updated: 2024/03/08 11:56:21 by mualkhid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker


SRCS := 	push_swap.c \
			errors.c	\
			init_a_to_b.c \
			init_b_to_a.c \
			push_commands.c \
			rev_rotate_commands.c \
			rotate_commands.c \
			sort_stack.c \
			sort_three.c \
			split.c \
			stack_init.c \
			stack_utils.c \
			swap_commands.c \

SRCSB := checker.c \
			checker_utils.c \
			errors.c	\
			init_a_to_b.c \
			init_b_to_a.c \
			push_commands.c \
			rev_rotate_commands.c \
			rotate_commands.c \
			sort_stack.c \
			sort_three.c \
			split.c \
			stack_init.c \
			stack_utils.c \
			swap_commands.c \
			get_next_line.c \
			get_next_line_utils.c \


OBJS := $(SRCS:.c=.o)
OBJSB := $(SRCSB:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
RM := rm -f

LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJSB) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJSB) $(LIBFT) $(PRINTF)



clean:
	make clean -C libft
	make clean -C ft_printf
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) $(NAME) $(NAME_BONUS)


re: fclean all

.PHONY: all clean fclean re bonus
