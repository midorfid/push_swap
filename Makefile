FILES =	rot_from_a_to_b.c 500_elems_sort.c additional_utils.c error_cases.c push_swap.c min_and_max.c my_atoi.c pushes.c rot_from_b_to_a.c	sort_3_num.c split.c utils.c rotates.c rotation_flags.c swap_top2_elems.c free_memory.c
SOURCES_DIRECTOY = srcs/
SRC			= $(addprefix $(SOURCES_DIRECTOY), $(FILES))
OBJ			= $(SRC:.c=.o)

NAME		= push_swap
HEADER		= ./include/push_swap.h
LIBFT		= Libft/libft.a
PRINTF		= ft_printf/libftprintf.a
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C Libft

$(PRINTF):
	make -C ft_printf

clean:
			rm -f $(OBJ)
			make clean -C Libft
			make clean -C ft_printf

fclean:		clean
			rm -rf $(NAME)
			make fclean -C Libft
			make fclean -C ft_printf

re:			fclean $(NAME)

.PHONY:		all clean fclean re