/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:42 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:21:06 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	adjoin_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->cheapest = 0;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	initiate_stack_a(t_stack **a, char **split_av)
{
	int		i;
	long	n;
	char	*arg;

	i = 0;
	while (split_av[i] != NULL)
	{
		arg = split_av[i];
		n = ft_atol(arg);
		if (syntax_error(arg) || duplicate_error(*a, (int)n))
		{
			free_array(split_av);
			free_errors(a);
			return (-1);
		}
		if (n > INT_MAX || n < INT_MIN)
		{
			free_array(split_av);
			free_errors(a);
			return (-1);
		}
		adjoin_node(a, (int)n);
		i++;
	}
	return (0);
}

void	push_init(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
