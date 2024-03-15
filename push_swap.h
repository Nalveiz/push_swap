/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:25:42 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 16:40:16 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "inc/libft.h"

typedef struct s_stack
{
	int				num;
	int				idx;
	int				total_command;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		error_syntax(char *av);
int		error_couple(t_stack *a, int n);
void	free_stack(t_stack **a);
void	free_errors(t_stack **a);

void	init_stack_a(t_stack **a, char **av);
char	**split(char *s, char c);

void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	current_idx(t_stack *x);
void	set_cheapest(t_stack *x);
t_stack	*get_cheapest(t_stack *x);
void	prep_for_push(t_stack **x, t_stack *top_node, char stack_name);

int		stack_len(t_stack *x);
t_stack	*find_last(t_stack *a);
bool	stack_sorted(t_stack *a);
t_stack	*find_max(t_stack *a);
t_stack	*find_min(t_stack *a);

void	pa(t_stack **a, t_stack **b, bool value);
void	pb(t_stack **a, t_stack **b, bool value);
void	sa(t_stack **a, bool value);
void	sb(t_stack **b, bool value);
void	ss(t_stack **a, t_stack **b, bool value);
void	ra(t_stack **a, bool value);
void	rb(t_stack **b, bool value);
void	rr(t_stack **a, t_stack **b, bool value);
void	rra(t_stack **a, bool value);
void	rrb(t_stack **b, bool value);
void	rrr(t_stack **a, t_stack **b, bool value);

void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);

#endif
