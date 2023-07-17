/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_cases.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 15:15:03 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:53:51 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_stack **head)
{
	t_stack	*lst;

	lst = *head;
	while (lst && lst->next)
	{
		if (lst->num > lst->next->num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	no_duplicates(t_stack *lst)
{
	t_stack	*test;

	while (lst != NULL && lst->next != NULL)
	{
		test = lst->next;
		while (test != NULL)
		{
			if (test->num == lst->num)
				return (1);
			test = test->next;
		}
		lst = lst->next;
	}
	return (0);
}
