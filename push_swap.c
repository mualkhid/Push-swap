/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:42 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:20:27 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_args(int ac, char **av, t_stack **a)
{
	char	**split_av;
	int		i;

	i = 1;
	while (i < ac)
	{
		split_av = split(av[i], ' ');
		if (initiate_stack_a(a, split_av) == -1)
		{
			free_array(split_av);
			continue ;
		}
		free_array(split_av);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else
		process_args(ac, av, &a);
	if (!stack_sorted(a))
	{
		if (get_len(a) == 2)
			sa(&a, false);
		else if (get_len(a) == 3)
			sort_3(&a);
		else
			stack_sorter(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
