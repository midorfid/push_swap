/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot_from_b_to_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 18:05:27 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/27 16:58:11 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pos_b_between_2a_nodes(t_data *data2, t_stack *b, t_stack *a)
{
	int		y;
	int		frst_con_check;
	int		qq;

	y = 1;
	frst_con_check = 0;
	qq = INT32_MAX;
	while (a != NULL && a->next != NULL)
	{
		if (lstlast(b)->num < a->next->num && lstlast(b)->num > a->num
			&& a->num - a->next->num < qq)
		{
			qq = a->num - a->next->num;
			data2->goldfish.b_node_pos = y;
			frst_con_check = 1;
		}
		a = a->next;
		y++;
	}
	if (!frst_con_check)
		data2->goldfish.b_node_pos = data2->size_a;
}

void	find_pos_in_a(t_data *data2, t_stack *b, t_stack *a)
{
	if (lstlast(b)->num > data2->extreme.max_b)
		data2->goldfish.b_node_pos = data2->extreme.max_node;
	else if (lstlast(b)->num < data2->extreme.min_b)
		data2->goldfish.b_node_pos = data2->extreme.min_node;
	else
		pos_b_between_2a_nodes(data2, b, a);
}

void	find_rot_from_b_to_a(t_data *data2, t_stack **b, t_stack **a)
{
	int	y;

	y = -1;
	find_pos_in_a(data2, *b, *a);
	data2->goldfish.rot_a_for = data2->size_a - data2->goldfish.b_node_pos;
	data2->goldfish.rot_a_back = data2->goldfish.b_node_pos;
	if (data2->goldfish.rot_a_for < data2->goldfish.rot_a_back)
	{
		while (++y < data2->goldfish.rot_a_for)
		{
			rotate_forward(a);
			ft_printf("rra\n");
			data2->operations++;
		}
	}
	else
	{
		while (++y < data2->goldfish.rot_a_back)
		{
			rotate_backwards(a);
			ft_printf("ra\n");
			data2->operations++;
		}
	}
}
