/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_memory.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/18 17:05:07 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:53:44 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	free_stack(t_stack **lst)
{
	void	*temp;

	temp = NULL;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	free (lst);
	return (0);
}

int	free_input(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
	return (0);
}
