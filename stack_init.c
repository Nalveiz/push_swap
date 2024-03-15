/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:49:06 by musozer           #+#    #+#             */
/*   Updated: 2024/03/13 21:40:57 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->num = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_couple(*a, (int)n))
			free_errors(a);
		add_node(a, (int)n);
		i++;
	}
}

t_stack	*get_cheapest(t_stack *x)
{
	if (!x)
		return (NULL);
	while (x)
	{
		if (x->cheapest)
			return (x);
		x = x->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **x, t_stack *top_node, char stack_name)
{
	while (*x != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(x, false);
			else
				rra(x, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(x, false);
			else
				rrb(x, false);
		}
	}
}
