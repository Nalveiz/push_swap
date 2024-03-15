/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:10:12 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 16:40:45 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack **a)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = find_last(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool value)
{
	r_rotate(a);
	if (!value)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool value)
{
	r_rotate(b);
	if (!value)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool value)
{
	r_rotate(a);
	r_rotate(b);
	if (!value)
		write(1, "rrr\n", 4);
}
