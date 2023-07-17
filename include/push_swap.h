/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 19:21:17 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/07/17 11:53:19 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_minmax
{
	int				max_b;
	int				max_node;
	int				min_b;
	int				min_node;
}	t_minmax;

typedef struct s_rots
{
	int				rot_a_for;
	int				rot_b_for;
	int				rot_a_back;
	int				rot_b_back;
	int				least_roll;
	int				b_node_pos;
	int				flag;
}	t_rots;

typedef struct s_data
{
	int				size_a;
	int				size_b;
	int				current_size;
	int				flag;
	int				rot;
	int				operations;
	struct s_rots	goldfish;
	struct s_minmax	extreme;
}	t_data;

void	min_node_first(t_stack **a, t_data *data2);
void	rotate_until_min_first(t_stack **a, t_data *data2);
void	sort_size4_list(t_stack **a, t_stack **b, t_data data, t_data data2);
int		better_strlen(char *str);
void	print_lst(t_stack *head);
int		check_sorted(t_stack **lst);
void	extra_checks(t_stack **a);
int		free_input(char **input);
int		free_stack(t_stack **lst);
int		lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int num);
void	sort_5h_elems(t_data *data, t_stack **a, t_stack **b, t_data *data2);
void	find_rot_from_b_to_a(t_data *data2, t_stack **b, t_stack **a);
void	lstadd_front(t_stack **lst, t_stack *new);
t_stack	*lstlast(t_stack *lst);
t_stack	**binary_input(char **input, int w_count);
void	sort_three(t_stack **a);
void	sec_stage_rotate_a(t_data *data, t_stack *a, t_stack *b);
void	first_push_to_b(t_stack **a, t_stack **b);
void	rotate_until_max_first(t_stack **b, t_data *data);
void	find_max2(t_data *data, t_stack *lst);
void	find_min2(t_data *data, t_stack *lst);
void	no_par_is_digit(int argc, char **argv);
int		no_duplicates(t_stack *lst);
void	rotate_best_rot(t_data *data, t_stack **a, t_stack **b);
t_rots	find_apos_inb(t_data *data, t_stack *a, t_stack *b);
void	find_least_rot_flag123(t_data *data, int i);
void	find_min_ascending(t_data *data, t_stack *lst);
void	find_max_ascending(t_data *data, t_stack *lst);
void	find_min_descending(t_data *data, t_stack *lst);
void	find_max_descending(t_data *data, t_stack *lst);
int		fill_list(char **argv, int *argc, t_stack **a);
void	swap_top2(t_stack **lst);
void	print_lst1(t_stack *head, int argc);
void	rotate_forward(t_stack	**head);
void	rotate_backwards(t_stack	**head);
int		size_list(t_stack *lst);
t_stack	*find_penultimate(t_stack *lst);
void	print_b(t_stack *head);
void	rotation_flag1(t_data *data, t_stack **a, t_stack **b);
void	rotation_flag2(t_data *data, t_stack **a, t_stack **b);
void	rotation_flag3(t_data *data, t_stack **a, t_stack **b);
void	rotation_flag4(t_data *data, t_stack **a, t_stack **b);
void	rotation_flag5(t_data *data, t_stack **a, t_stack **b);
void	rotation_flag6(t_data *data, t_stack **a, t_stack **b);
void	push_to_lst(t_stack *a, t_stack *b);
void	swap_sa(t_stack **lst);

#endif