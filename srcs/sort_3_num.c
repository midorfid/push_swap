/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_num.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 15:00:13 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/31 15:11:01 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	second_case(t_stack **a)
{
	swap_top2(a);
	rotate_backwards(a);
	ft_printf("sa\n");
	ft_printf("rra\n");
}

void	fourth_case(t_stack **a)
{
	swap_top2(a);
	rotate_forward(a);
	ft_printf("sa\n");
	ft_printf("ra\n");
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third && ft_printf("sa\n"))
		swap_top2(a);
	else if (first > second && second > third)
		second_case(a);
	else if (first > second && second < third && ft_printf("ra\n"))
		rotate_forward(a);
	else if (first < second && second > third && first < third)
		fourth_case(a);
	else if (first < second && second > third && ft_printf("rra\n"))
		rotate_backwards(a);
}
