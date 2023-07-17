/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 19:08:01 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 13:22:17 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	min_node_first(t_stack **a, t_data *data2)
{
	int	size;

	size = size_list(*a);
	find_min_ascending(data2, *a);
	if ((size - data2->extreme.min_node) < data2->extreme.min_node)
	{
		if ((*a)->num != data2->extreme.min_b)
			rotate_until_min_first(a, data2);
	}
	else
	{
		while ((*a)->num != data2->extreme.min_b)
		{
			rotate_backwards(a);
			ft_printf("ra\n");
			data2->operations++;
		}
	}
}

void	sort_size4_list(t_stack **a, t_stack **b, t_data data, t_data data2)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = 0;
	new->next = NULL;
	first_push_to_b(a, b);
	data.operations++;
	sort_three(a);
	find_max_ascending(&data2, *a);
	find_min_ascending(&data2, *a);
	data2.size_b = size_list(*b);
	data2.size_a = size_list(*a);
	lstadd_front(b, new);
	find_rot_from_b_to_a(&data2, b, a);
	push_to_lst(*b, *a);
	ft_printf("pa\n");
	min_node_first(a, &data2);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	t_data	data;
	t_data	data2;

	a = binary_input(argv, argc);
	extra_checks(a);
	b = malloc(sizeof(t_stack **));
	if (size_list(*a) == 2)
	{
		rotate_forward(a);
		ft_printf("ra\n");
	}
	else if (size_list(*a) == 3)
		sort_three(a);
	else if (size_list(*a) == 4)
		sort_size4_list(a, b, data, data2);
	else
		sort_5h_elems(&data, a, b, &data2);
	// print_lst(*a);
	// if (check_sorted(a) && ft_printf("not sorted"))
	// 	exit (EXIT_FAILURE);
	free_stack(a);
	if (argc > 4)
		free_stack(b);
	else
		free(b);
	// system("leaks a.out");
}

// system("leaks push_swap");
// if (check_sorted(a) && ft_printf("not sorted"))
// 	exit (EXIT_FAILURE);
// print_lst(*a);