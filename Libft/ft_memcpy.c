/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:25:46 by ashevchu      #+#    #+#                 */
/*   Updated: 2022/10/20 15:35:12 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (0);
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}
