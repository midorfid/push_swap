/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:38:24 by ashevchu      #+#    #+#                 */
/*   Updated: 2022/11/03 18:48:29 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*str, int s)
{
	size_t			i;
	char			*str1;
	char			brk_pnt;

	i = 0;
	brk_pnt = s;
	str1 = (char *)str;
	while (str1[i])
	{
		if (brk_pnt == str1[i])
			return (&str1[i]);
		i++;
	}
	if (str1[i] == brk_pnt)
		return (&str1[i]);
	return (NULL);
}
