/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:24 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 16:41:08 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **a)
{
	t_stack	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = find_last(*a);
	last_node->next = (*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool value)
{
	rotate(a);
	if (!value)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool value)
{
	rotate(b);
	if (!value)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool value)
{
	rotate(a);
	rotate(b);
	if (!value)
		write(1, "rr\n", 3);
}
