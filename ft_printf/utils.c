/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 22:40:07 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 10:29:14 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd1(char *s, int fd)
{
	size_t	x;
	size_t	str_len;

	x = 0;
	str_len = ft_strlen1(s);
	write(fd, s, str_len);
}

void	ft_putchar_fd1(char c, int fd)
{
	write (fd, &c, 1);
}

char	*ft_strdup1(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (ptr);
	while (i >= 0)
	{
		ptr[i] = s1[i];
		i--;
	}
	return (ptr);
}
