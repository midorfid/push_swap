/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 19:47:19 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 10:29:25 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char			*ft_strdup1(const char *s1);

char			*ft_itoa1(int n);

size_t			ft_strlen1(const char *s);

void			ft_putstr_fd1(char *s, int fd);

void			ft_putchar_fd1(char c, int fd);

int				ft_printf(const char *ptr, ...);

int				formats(va_list args, const char format);

int				print_percent(void);

int				print_unsign(unsigned int n);

char			*unsign_int_mem_alloc(unsigned int n);

char			*unsign_fill_arr(unsigned int n, char	*res, int int_count);

int				print_int(int n);

int				print_str(char	*s);

int				print_ptr(unsigned long long p);

int				print_ptr_ox(unsigned long long p);

int				print_hexi(unsigned int p, const char format);

#endif