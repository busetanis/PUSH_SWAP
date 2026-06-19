# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 13:46:19 by butanis           #+#    #+#              #
#    Updated: 2026/05/05 20:25:20 by butanis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.

SRCS =main.c \
	operations/operation_push.c \
	operations/operation_reverse_rotate.c \
	operations/operation_rotate.c \
	operations/operation_swap.c \
	stack/stack.c \
	parsing/error.c \
	parsing/input_validation.c \
	parsing/validation.c \
	parsing/validation1.c \
	parsing/compute_disorder.c \
	parsing/ft_split.c\
	parsing/sort_dispatcher.c \
	algorithms/complex_quick_sort.c \
	algorithms/complex_quick_pivot.c \
	algorithms/complex_quick_small_sort.c \
	algorithms/complex_quick_a.c \
	algorithms/complex_quick_b.c \
	algorithms/medium_chunk_sort.c \
	algorithms/medium_chunk_small_sort.c \
	algorithms/simple.c\
	algorithms/simple1.c\
	bench/bench_print.c\
	bench/bench.c\
	bench/flags.c \
	

OBJS	= $(SRCS:.c=.o)

GREEN	= \033[0;32m
BLUE	= \033[0;34m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)$(NAME) created!!!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(RESET)"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re