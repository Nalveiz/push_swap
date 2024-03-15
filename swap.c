/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:03:20 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 16:43:57 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

void	sa(t_stack **a, bool value)
{
	swap(a);
	if (!value)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool value)
{
	swap(b);
	if (!value)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool value)
{
	swap(a);
	swap(b);
	if (!value)
		write(1, "ss\n", 3);
}
