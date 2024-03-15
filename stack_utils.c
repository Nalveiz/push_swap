/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:46:50 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 16:45:30 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*find_max(t_stack *a)
{
	long	max;
	t_stack	*max_node;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (a->num > max)
		{
			max = a->num;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *a)
{
	long	min;
	t_stack	*min_node;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->num < min)
		{
			min = a->num;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_len(t_stack *x)
{
	int	count;

	if (!x)
		return (0);
	count = 0;
	while (x)
	{
		x = x->next;
		count++;
	}
	return (count);
}
