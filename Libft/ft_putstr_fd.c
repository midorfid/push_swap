/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:56:16 by ashevchu      #+#    #+#                 */
/*   Updated: 2022/11/03 18:44:54 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	x;
	size_t	str_len;

	x = 0;
	str_len = ft_strlen(s);
	write(fd, s, str_len);
}
