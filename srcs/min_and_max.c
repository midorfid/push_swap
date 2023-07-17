/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_and_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 18:05:27 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:53:56 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_max_descending(t_data *data, t_stack *lst)
{
	int	i;

	i = 1;
	if ((lst)->num)
	{
		data->extreme.max_b = (lst)->num;
		data->extreme.max_node = 0;
	}
	while ((lst) != NULL)
	{
		if (data->extreme.max_b < (lst)->num)
		{
			data->extreme.max_b = (lst)->num;
			data->extreme.max_node = i - 1;
		}
		(lst) = (lst)->next;
		i++;
	}
}

void	find_min_descending(t_data *data, t_stack *lst)
{
	int	i;

	i = 1;
	if (lst != NULL)
	{
		data->extreme.min_b = (lst)->num;
		data->extreme.min_node = i;
	}
	while ((lst) != NULL)
	{
		if (data->extreme.min_b > (lst)->num)
		{
			data->extreme.min_b = (lst)->num;
			data->extreme.min_node = i - 1;
		}
		(lst) = (lst)->next;
		i++;
	}
}

void	find_max_ascending(t_data *data2, t_stack *lst)
{
	int	i;

	i = 1;
	if ((lst)->num)
	{
		data2->extreme.max_b = (lst)->num;
		data2->extreme.max_node = i;
	}
	while ((lst) != NULL)
	{
		if (data2->extreme.max_b < (lst)->num)
		{
			data2->extreme.max_b = (lst)->num;
			data2->extreme.max_node = i;
		}
		(lst) = (lst)->next;
		i++;
	}
}

void	find_min_ascending(t_data *data2, t_stack *lst)
{
	int	i;

	i = 1;
	if (lst != NULL)
	{
		data2->extreme.min_b = (lst)->num;
		data2->extreme.min_node = 0;
	}
	while ((lst) != NULL)
	{
		if (data2->extreme.min_b > (lst)->num)
		{
			data2->extreme.min_b = (lst)->num;
			data2->extreme.min_node = i - 1;
		}
		(lst) = (lst)->next;
		i++;
	}
}
