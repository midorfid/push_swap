/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   500_elems_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 20:36:41 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 13:18:34 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_first_2_to_b(t_data *data, t_stack **a, t_stack **b)
{
	first_push_to_b(a, b);
	data->operations++;
	push_to_lst(*a, *b);
	ft_printf("pb\n");
	data->operations++;
	data->size_b = size_list(*b);
	data->size_a = size_list(*a);
	find_max_descending(data, *b);
	find_min_descending(data, *b);
	if ((*b)->num != data->extreme.max_b)
		rotate_until_max_first(b, data);
}

void	sort_descendin_b(t_data *data, t_stack **a, t_stack **b)
{
	find_max_descending(data, *b);
	find_min_descending(data, *b);
	while (0 < data->size_a - 3)
	{
		rotate_best_rot(data, a, b);
		data->size_b++;
		data->size_a--;
	}
	if ((*b)->num != data->extreme.max_b)
		rotate_until_max_first(b, data);
}

void	sort_ascendin_a(t_data *data, t_stack **a, t_stack **b, t_data *data2)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = 0;
	sort_three(a);
	find_max_ascending(data2, *a);
	find_min_ascending(data2, *a);
	data2->size_b = size_list(*b);
	data2->size_a = size_list(*a);
	while (0 < data2->size_b - 1)
	{
		find_rot_from_b_to_a(data2, b, a);
		push_to_lst(*b, *a);
		ft_printf("pa\n");
		find_max_ascending(data2, *a);
		find_min_ascending(data2, *a);
		data2->operations++;
		data2->size_b--;
		data2->size_a++;
	}
	lstadd_front(b, new);
	find_rot_from_b_to_a(data2, b, a);
	push_to_lst(*b, *a);
}

void	sort_5h_elems(t_data *data, t_stack **a, t_stack **b, t_data *data2)
{
	data->operations = 0;
	data2->operations = 0;
	push_first_2_to_b(data, a, b);
	sort_descendin_b(data, a, b);
	sort_ascendin_a(data, a, b, data2);
	ft_printf("pa\n");
	data->operations++;
	find_min_ascending(data2, *a);
	min_node_first(a, data2);
}
// ft_printf("OPERATIONS_COUNT:%d\n", data->operations);
// ft_printf("OPERATIONS_COUNT:%d\n", data2->operations);