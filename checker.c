/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:49 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/08 16:57:17 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void process_input(int ac, char **av, t_stack **a)
{
    char **split_av;
    int i;

    i = 1;
    while (i < ac)
    {
        split_av = split(av[i], ' ');
        if (init_stack_a(a, split_av) == -1)
        {
            free_split_array(split_av);
            continue;
        }
        free_split_array(split_av);
        i++;
    }
}

void process_commands(t_stack **a, t_stack **b)
{
    char *next_line;

    next_line = NULL;
    next_line = (get_next_line(0, next_line));
    while (next_line)
    {
        apply_command(a, b, next_line);
        free(next_line);
        next_line = (get_next_line(0, next_line));
    }
}

void print_result(t_stack *a)
{
    int len;

    len = stack_len(a);
    if (stack_sorted(a) && stack_len(a) == len)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (0);
    process_input(ac, av, &a);
    process_commands(&a, &b);
    print_result(a);
    free_stack(&a);
    free_stack(&b);
    return (0);
}

// #include "push_swap.h"

// int	main(int ac, char **av)
// {
//     t_stack	*a;
//     t_stack	*b;
//     char	*next_line;
//     char    **split_av;
//     int		len;
//     int     i;

//     a = NULL;
//     b = NULL;
//     next_line = NULL;
//     if (ac == 1 || (ac == 2 && !av[1][0]))
//         return (0);
//     else
//     {
//         i = 1;
//         while (i < ac)
//         {
//             split_av = split(av[i], ' ');
//             if (init_stack_a(&a, split_av) == -1)
//             {
//                 free_split_array(split_av);
//                 continue;
//             }
//             free_split_array(split_av);
//             i++;
//         }
//     }
//     len = stack_len(a);
//     next_line = (get_next_line(0, next_line));
//     while (next_line)
//     {
//         apply_command(&a, &b, next_line);
//         free(next_line);
//         next_line = (get_next_line(0, next_line));
//     }
//     if (stack_sorted(a) && stack_len(a) == len)
//         write(1, "OK\n", 3);
//     else
//         write(1, "KO\n", 3);
//     free_stack(&a);
//     free_stack(&b);
//     return (0);
// }















// // int	main(int ac, char **av)
// // {
// // 	t_stack	*a;
// // 	t_stack	*b;
// // 	char	*next_line;
// // 	char	**split_av;
// // 	int		len;
// // 	int		i;
// // 	int		j;
// // 	int k;

// // 	split_av = NULL;
// // 	a = NULL;
// // 	b = NULL;
// // 	next_line = NULL;
// // 	k = 0;
// // 	if (ac == 1 || (ac == 2 && !av[1][0]))
// // 		return (0);
// // 	else
// // 	{
// // 		i = 1;
// // 		while (i < ac)
// // 		{
// // 			split_av = split(av[i], ' ');
// // 			j = 0;
// // 			while (split_av[j] != NULL)
// // 			{
// // 				init_stack_checker(&a, split_av[j]);
// // 				free(split_av[j]);
// // 				j++;
// // 			}
// // 			free(split_av);
// // 			i++;
// // 		}
// // 	}
// // 	len = stack_len(a);
// // 	while (next_line != NULL || k == 0)
// // 	{
// // 		next_line = (get_next_line(0, next_line));
// // 		apply_command(&a, &b, next_line);
// // 		free(next_line);
// // 		k++;
// // 	}
// // 	free(next_line);
// // 	if (stack_sorted(a) && stack_len(a) == len)
// // 		write(1, "OK\n", 3);
// // 	else
// // 		write(1, "KO\n", 3);
// // 	free_stack(&a);
// // 	free_stack(&b);
// // 	return (0);
// // }

// // #include "push_swap.h"

// // int	main(int ac, char **av)
// // {
// //     t_stack	*a;
// //     t_stack	*b;
// //     char	*next_line;
// //     char    **split_av = NULL;
// //     int		len;
// //     int     i;

// //     a = NULL;
// //     b = NULL;
// //     next_line = NULL;
// //     if (ac == 1)
// //         return (1);
// //     else if (ac >= 2)
// //     {
// //         split_av = split(av[1], ' ');
// //         av = split_av;
// //     }
// //     init_stack_a(&a, av + 1);
// //     len = stack_len(a);
// //     next_line = (get_next_line(0, next_line));
// //     while (next_line)
// //     {
// //         apply_command(&a, &b, next_line);
// //         next_line = (get_next_line(0, next_line));
// //     }
// //     if (stack_sorted(a) && stack_len(a) == len)
// //         write(1, "OK\n", 3);
// //     else
// //         write(1, "KO\n", 3);
// //     free(a);
// //     if (split_av != NULL)
// //     {
// //         i = 0;
// //         while (split_av[i] != NULL) {
// //             free(split_av[i]);
// //             i++;
// //         }
// //         free(split_av);
// //     }
// //     return (0);
// // }
