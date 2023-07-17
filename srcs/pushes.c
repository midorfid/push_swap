/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:54:40 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 13:21:09 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_lst(t_stack *from, t_stack *to)
{
	t_stack	*temp_from;
	t_stack	*temp_to;
	t_stack	*new_last_from;

	if (!size_list(from))
		return ;
	temp_from = lstlast(from);
	temp_to = lstlast(to);
	new_last_from = find_penultimate(from);
	temp_to->next = temp_from;
	temp_from->next = NULL;
	new_last_from->next = NULL;
}

void	first_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*new_last_a;

	if (!size_list(*a))
		return ;
	temp_a = lstlast(*a);
	*b = lstnew(temp_a->num);
	free(lstlast(*a));
	new_last_a = find_penultimate(*a);
	(*b)->next = NULL;
	temp_a->next = NULL;
	new_last_a->next = NULL;
	ft_printf("pb\n");
}
