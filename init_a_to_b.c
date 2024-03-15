/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:29:20 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 15:51:35 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_idx(t_stack *x)
{
	int	i;
	int	median;

	i = 0;
	if (!x)
		return ;
	median = stack_len(x) / 2;
	while (x)
	{
		x->idx = i;
		if (i <= median)
			x->above_median = true;
		else
			x->above_median = false;
		x = x->next;
		++i;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	match_idx;

	while (a)
	{
		match_idx = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > match_idx)
			{
				match_idx = current_b->num;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match_idx == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->total_command = a->idx;
		if (!(a->above_median))
			a->total_command = len_a - (a->idx);
		if (a->target_node->above_median)
			a->total_command += a->target_node->idx;
		else
			a->total_command += len_b - (a->target_node->idx);
		a = a->next;
	}
}

void	set_cheapest(t_stack *x)
{
	long	cheapest_val;
	t_stack	*cheapest;

	if (!x)
		return ;
	cheapest_val = LONG_MAX;
	while (x)
	{
		if (x->total_command < cheapest_val)
		{
			cheapest_val = x->total_command;
			cheapest = x;
		}
		x = x->next;
	}
	cheapest->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_idx(a);
	current_idx(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}
