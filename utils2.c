/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:24:21 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:24:22 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = get_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	push_init(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	set_min_on_top(t_stack **a)
{
	while ((*a)->nbr != get_min(*a)->nbr)
	{
		if (get_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	free_array(char **split_array)
{
	int	i;

	i = 0;
	while (split_array[i] != NULL)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
