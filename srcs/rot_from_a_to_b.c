/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot_from_a_to_b.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 18:05:27 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:54:06 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// both backwards
// b forward a backward
void	find_least_rot_flag456(t_data *data, int i)
{
	data->goldfish.rot_b_back = data->goldfish.b_node_pos;
	data->goldfish.rot_a_back = i;
	if (data->goldfish.least_roll > data->goldfish.rot_b_back
		&& data->goldfish.rot_b_back > data->goldfish.rot_a_back)
	{
		data->goldfish.least_roll = data->goldfish.rot_b_back;
		data->goldfish.flag = 4;
	}
	else if (data->goldfish.least_roll > data->goldfish.rot_a_back
		&& data->goldfish.rot_b_back < data->goldfish.rot_a_back)
	{
		data->goldfish.least_roll = data->goldfish.rot_a_back;
		data->goldfish.flag = 5;
	}
	data->goldfish.rot_b_for = data->size_b - data->goldfish.b_node_pos;
	if (data->goldfish.least_roll
		> data->goldfish.rot_b_for + data->goldfish.rot_a_back)
	{
		data->goldfish.least_roll = data->goldfish.rot_b_for
			+ data->goldfish.rot_a_back;
		data->goldfish.flag = 6;
	}
}

//both forward
//a forward b backward

void	find_least_rot_flag123(t_data *data, int i)
{
	data->goldfish.rot_b_for = data->size_b - data->goldfish.b_node_pos;
	data->goldfish.rot_a_for = data->size_a - i;
	if (data->goldfish.least_roll > data->goldfish.rot_b_for
		&& data->goldfish.rot_b_for > data->goldfish.rot_a_for)
	{
		data->goldfish.least_roll = data->goldfish.rot_b_for;
		data->goldfish.flag = 1;
	}
	else if (data->goldfish.least_roll > data->goldfish.rot_a_for
		&& data->goldfish.rot_a_for > data->goldfish.rot_b_for)
	{
		data->goldfish.least_roll = data->goldfish.rot_a_for;
		data->goldfish.flag = 2;
	}
	data->goldfish.rot_b_back = data->goldfish.b_node_pos;
	if (data->goldfish.least_roll
		> data->goldfish.rot_b_back + data->goldfish.rot_a_for)
	{
		data->goldfish.least_roll = data->goldfish.rot_b_back
			+ data->goldfish.rot_a_for;
		data->goldfish.flag = 3;
	}
	find_least_rot_flag456(data, i);
}

void	pos_a_between_2b_nodes(t_data *data, t_stack *a, t_stack *b)
{
	int		y;
	int		frst_con_check;
	int		qq;

	y = 1;
	frst_con_check = 0;
	qq = INT32_MAX;
	while (b != NULL && b->next != NULL)
	{
		if (a->num > b->next->num && a->num < b->num
			&& b->num - b->next->num > 0 && b->num - b->next->num < qq)
		{
			qq = b->num - b->next->num;
			data->goldfish.b_node_pos = y;
			frst_con_check = 1;
		}
		b = b->next;
		y++;
	}
	if (!frst_con_check)
		data->goldfish.b_node_pos = data->size_b;
}

t_rots	find_apos_inb(t_data *data, t_stack *a, t_stack *b)
{
	int		i;
	t_rots	ideal_rot;

	i = 1;
	while (a != NULL)
	{
		if (a->num > data->extreme.max_b)
			data->goldfish.b_node_pos = data->extreme.max_node;
		else if (a->num < data->extreme.min_b)
			data->goldfish.b_node_pos = data->extreme.min_node;
		else
			pos_a_between_2b_nodes(data, a, b);
		find_least_rot_flag123(data, i);
		if (data->goldfish.least_roll < data->rot)
		{
			ideal_rot = data->goldfish;
			data->rot = data->goldfish.least_roll;
		}
		a = a->next;
		i++;
	}
	return (ideal_rot);
}

void	rotate_best_rot(t_data *data, t_stack **a, t_stack **b)
{
	data->rot = INT32_MAX;
	data->goldfish.flag = 0;
	data->goldfish.least_roll = INT32_MAX;
	data->goldfish = find_apos_inb(data, *a, *b);
	if (data->goldfish.flag == 1)
		rotation_flag1(data, a, b);
	if (data->goldfish.flag == 2)
		rotation_flag2(data, a, b);
	if (data->goldfish.flag == 3)
		rotation_flag3(data, a, b);
	if (data->goldfish.flag == 4)
		rotation_flag4(data, a, b);
	if (data->goldfish.flag == 5)
		rotation_flag5(data, a, b);
	if (data->goldfish.flag == 6)
		rotation_flag6(data, a, b);
	if (data->goldfish.flag != 0)
	{
		push_to_lst(*a, *b);
		data->operations++;
	}
	find_max_descending(data, *b);
	find_min_descending(data, *b);
}
