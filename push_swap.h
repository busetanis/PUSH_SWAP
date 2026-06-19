/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:47:59 by butanis           #+#    #+#             */
/*   Updated: 2026/05/06 21:13:45 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int		enabled;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	char	*strategy;
	char	*complexity;
}	t_bench;

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);
void	ft_pa(t_node **a, t_node **b, int j, t_bench *bench);
void	ft_pb(t_node **a, t_node **b, int j, t_bench *bench);
void	ft_rra(t_node **a, int j, t_bench *bench);
void	ft_ra(t_node **a, int j, t_bench *bench);
void	ft_rb(t_node **b, int j, t_bench *bench);
void	ft_sa(t_node **a, int j, t_bench *bench);
void	ft_sb(t_node **b, int j, t_bench *bench);
void	ft_ss(t_node **a, t_node **b, int j, t_bench *bench);
void	ft_rrb(t_node **b, int j, t_bench *bench);
void	ft_rrr(t_node **a, t_node **b, int j, t_bench *bench);
void	ft_rr(t_node **a, t_node **b, int j, t_bench *bench);
void	error_exit(t_node **a);
int		validation_number(char *string);
long	ft_atol(const char *str);
int		validation_duplicate(t_node *stack, int value);
void	validation_args(int arg_count, char **arg_value, t_node **a);
void	validation_args_from_index(int ac, char **av, t_node **a, int start);
char	**ft_split(const char *s, char c);
void	add_split_values(t_node **a, char **split);
void	add_value_to_stack(t_node **a, char *str);
void	error_exit_split(t_node **a, char **split);
void	free_split(char **split);
int		is_bench_flag(char *str);
void	init_bench(t_bench *bench);
void	count_op(t_bench *bench, char *op);
void	print_bench(t_bench *bench);
int		is_strategy_flag(char *str);
int		get_start_index(int ac, char **av);
void	run_strategy(char *flag, t_node **a, t_node **b, t_bench *bench);
int		is_any_flag(char *str);
double	compute_disorder(t_node *a);
void	sort_dispatcher(t_node **a, t_node **b, t_bench *bench);
void	complex_quick_sort(t_node **a, t_node **b, t_bench *bench);
void	quick_sort_a(t_node **a, t_node **b, int size, t_bench *bench);
void	quick_sort_b(t_node **a, t_node **b, int size, t_bench *bench);
int		complex_quick_pivot(t_node *stack, int size);
void	sort_two_a(t_node **a, t_bench *bench);
void	sort_three_a(t_node **a, t_bench *bench);
void	sort_two_b(t_node **a, t_node **b, t_bench *bench);
int		get_min_position(t_node **stack);
void	move_min_to_top(t_node **a, t_bench *bench);
void	sort_3(t_node **a, t_bench *bench);
void	sort_4(t_node **a, t_node **b, t_bench *bench);
void	sort_5(t_node **a, t_node **b, t_bench *bench);
void	simple_sort(t_node **a, t_node **b, t_bench *bench);
void	index_stack(t_node **stack);
void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size,
			t_bench *bench);
int		get_max_position(t_node **b);
void	pull_to_a(t_node **a, t_node **b, t_bench *bench);
void	medium_chunk_sort(t_node **a, t_node **b, t_bench *bench);
void	sort_small(t_node **a, t_node **b, t_bench *bench);

#endif
