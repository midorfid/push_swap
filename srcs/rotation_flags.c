/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 20:20:58 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 12:53:54 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotation_flag1(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 1)
	{
		while (i < data->goldfish.rot_a_for)
		{
			rotate_forward(a);
			rotate_forward(b);
			ft_printf("rr\n");
			data->operations++;
			i++;
		}
		while (i < data->goldfish.rot_b_for)
		{
			rotate_forward(b);
			ft_printf("rb\n");
			data->operations++;
			i++;
		}
	}
}

void	rotation_flag2(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 2)
	{
		while (i < data->goldfish.rot_b_for)
		{
			rotate_forward(a);
			rotate_forward(b);
			ft_printf("rr\n");
			data->operations++;
			i++;
		}
		while (i < data->goldfish.rot_a_for)
		{
			rotate_forward(a);
			ft_printf("ra\n");
			data->operations++;
			i++;
		}
	}
}

void	rotation_flag3(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 3)
	{
		while (i < data->goldfish.rot_a_for)
		{
			rotate_forward(a);
			ft_printf("ra\n");
			data->operations++;
			i++;
		}
		i = 0;
		while (i < data->goldfish.rot_b_back)
		{
			rotate_backwards(b);
			ft_printf("rrb\n");
			data->operations++;
			i++;
		}
	}
}

void	rotation_flag4(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 4)
	{
		while (i < data->goldfish.rot_a_back)
		{
			rotate_backwards(a);
			rotate_backwards(b);
			ft_printf("rrr\n");
			data->operations++;
			i++;
		}
		while (i < data->goldfish.rot_b_back)
		{
			rotate_backwards(b);
			ft_printf("rrb\n");
			data->operations++;
			i++;
		}
	}
}

void	rotation_flag5(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 5)
	{
		while (i < data->goldfish.rot_b_back)
		{
			rotate_backwards(a);
			rotate_backwards(b);
			ft_printf("rrr\n");
			data->operations++;
			i++;
		}
		while (i < data->goldfish.rot_a_back)
		{
			rotate_backwards(a);
			ft_printf("rra\n");
			data->operations++;
			i++;
		}
	}
}
