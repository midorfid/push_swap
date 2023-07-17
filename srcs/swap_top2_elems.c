/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_top2_elems.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 16:29:11 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 12:21:24 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_antepenultimate(t_stack *lst)
{
	if (lst && lst->next != NULL && lst->next->next != NULL)
	{
		if (lst->next->next->next != NULL)
		{
			while (lst->next->next->next != NULL)
				lst = lst->next;
			return (lst);
		}
		if (lst->next->next != NULL)
			return (lst);
	}
	return (lst);
}

//esli 2 arg
//esli 3+ arg
void	swap_top2(t_stack **lst)
{
	t_stack	*last;
	t_stack	*penultimate;
	t_stack	*antepenultimate;

	last = lstlast(*lst);
	penultimate = find_penultimate(*lst);
	if (lst && (*lst)->next != NULL && (*lst)->next->next == NULL)
	{
		last->next = *lst;
		*lst = last;
		(*lst)->next = NULL;
	}
	else
	{
		antepenultimate = find_antepenultimate(*lst);
		antepenultimate->next = last;
		last->next = penultimate;
		penultimate->next = NULL;
	}
}

// void	swap_sa(t_stack **lst)
// {
// 	int	temp;

// 	if (!lst || (*lst)->next == NULL)
// 		return ;
// 	temp = (*lst)->num;
// 	(*lst)->num = (*lst)->next->num;
// 	(*lst)->next->num = temp;
// }
