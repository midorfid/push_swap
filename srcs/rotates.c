/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotates.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:27:57 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:54:11 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_penultimate(t_stack *lst)
{
	if (lst == NULL)
		return (lst);
	if (lst->next == NULL)
		return (lst->next);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	rotate_forward(t_stack	**head)
{
	t_stack	*temp;
	t_stack	*tail;

	tail = lstlast(*head);
	temp = find_penultimate(*head);
	tail->next = *head;
	*head = tail;
	temp->next = NULL;
}

void	rotate_backwards(t_stack	**head)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *head;
	tail = lstlast(*head);
	*head = (*head)->next;
	tail->next = temp;
	temp->next = NULL;
}
