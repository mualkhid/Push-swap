/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:57 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/08 11:55:38 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
	{
		free(a);
		return (0);
	}
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;
    if (stack && *stack)
    {
        while (*stack)
        {
            tmp = (*stack)->next;
            free(*stack);
            *stack = tmp;
        }
    }
}

void	free_errors(t_stack **a, t_stack **b)
{
	ft_putendl_fd("Error", 2);
	if(a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	exit(EXIT_FAILURE);
}
