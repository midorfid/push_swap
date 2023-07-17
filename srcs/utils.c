/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 18:28:22 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 12:55:18 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	size_list(t_stack *lst)
{
	int	size;

	size = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	print_lst(t_stack *head)
{
	int	count;

	count = size_list(head);
	for (int i = 0; i < count; i++)
	{
		ft_printf("%d\n", head->num);
		head = head->next;
	}
}

void	rotate_until_max_first(t_stack **b, t_data *data)
{
	while ((*b)->num != data->extreme.max_b)
	{
		rotate_forward(b);
		ft_printf("rb\n");
		data->operations++;
	}
}

void	rotate_until_min_first(t_stack **a, t_data *data2)
{
	while ((*a)->num != data2->extreme.min_b)
	{
		rotate_forward(a);
		ft_printf("ra\n");
		data2->operations++;
	}
}
