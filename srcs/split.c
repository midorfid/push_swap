/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 18:05:19 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/23 20:54:19 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	**binary_input(char **input, int w_count)
{
	int		i;
	t_stack	**a;

	a = malloc(sizeof(t_stack **));
	if (!a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	*a = NULL;
	i = 0;
	while (++i < w_count)
	{
		if (fill_list(input, &i, a))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free_stack(a);
			exit (EXIT_FAILURE);
		}
	}
	return (a);
}
