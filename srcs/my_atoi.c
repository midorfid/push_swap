/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:43:09 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/25 17:46:05 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	atol_maxmin_int(long result)
{
	if (result > 2147483647 || result < -2147483648)
	{
		ft_printf("Error\n");
		exit (0);
	}
}

long	my_atol(const char *str)
{
	int			sign;
	long		result;
	int			c;

	sign = 1;
	result = 0;
	c = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n' || str[c] == '\v'
		|| str[c] == '\r' || str[c] == '\f')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	result = result * sign;
	atol_maxmin_int(result);
	return (result);
}

void	extra_checks(t_stack **a)
{
	if (no_duplicates(*a) && !free_stack(a))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (!check_sorted(a) && !free_stack(a))
	{
		exit (EXIT_SUCCESS);
	}
}

int	str_check(char	*str)
{
	int	i;

	i = -1;
	if (!ft_strlen(str))
		return (1);
	while (str[++i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
	}
	if (ft_atoi(str) != my_atol(str))
		return (1);
	return (0);
}

int	fill_list(char **input, int *j, t_stack **a)
{
	int		i;
	char	**str;

	i = -1;
	str = ft_split(input[*j], ' ');
	if (!str || !*str || !ft_strlen(input[*j]))
	{
		ft_putstr_fd ("Error\n", STDERR_FILENO);
		free_stack(a);
		exit (EXIT_FAILURE);
	}
	while (str[++i])
	{
		if (str_check(str[i]))
		{
			free_input(str);
			return (1);
		}
		if (lstadd_back(a, lstnew(ft_atoi(str[i]))) && !free_input(str))
			return (1);
	}
	free_input(str);
	return (0);
}
