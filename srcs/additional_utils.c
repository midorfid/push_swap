/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   additional_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 20:15:39 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 12:50:45 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// #include <stdio.h>

t_stack	*lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return (1);
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return (0);
	}
	temp = lstlast(*lst);
	temp->next = new;
	new->next = NULL;
	return (0);
}

void	rotation_flag6(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (data->goldfish.flag == 6)
	{
		while (i < data->goldfish.rot_b_for)
		{
			rotate_forward(b);
			ft_printf("rb\n");
			data->operations++;
			i++;
		}
		i = 0;
		while (i < data->goldfish.rot_a_back)
		{
			rotate_backwards(a);
			ft_printf("rra\n");
			data->operations++;
			i++;
		}
	}
}

t_stack	*lstnew(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

// int	better_strlen(char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
