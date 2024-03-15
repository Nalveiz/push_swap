/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:29 by musozer           #+#    #+#             */
/*   Updated: 2024/03/15 15:52:22 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *av)
{
	if (!(*av == '+' || *av == '-' || (*av >= '0' && *av <= '9')))
		return (1);
	if ((*av == '+' || *av == '-') && !(av[1] >= '0' && av[1] <= '9'))
		return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

int	error_couple(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*stack;

	if (!x)
		return ;
	stack = *x;
	while (stack)
	{
		tmp = stack->next;
		stack->num = 0;
		free(stack);
		stack = tmp;
	}
	*x = NULL;
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
